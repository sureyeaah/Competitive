{-# LANGUAGE OverloadedStrings #-}

module Main where
import           Control.Arrow
import           Data.Bool
import qualified Data.ByteString.Lazy.Char8  as C
import           Data.Function
import           Data.List
import           Data.List.Split
import qualified Data.Map                    as M
import qualified Data.Vector                 as V
import           Text.Parsec
import           Text.Parsec.ByteString.Lazy
import           Text.Parsec.Char

main :: IO ()
main = C.interact $
  C.lines >>> drop 1 >>> chunksOf 4 >>> map (parseInput >>> solve >>> show >>> C.pack) >>> C.unlines

n :: Int
n = 100

readInts :: C.ByteString -> [Int]
readInts bs =  read . C.unpack <$> C.words bs

parseInput :: [C.ByteString] -> ([Int], [Int], V.Vector Int)
parseInput [_, m, c, p] = (readInts m, readInts c, V.fromList $ readInts p)

solve :: ([Int], [Int], V.Vector Int) -> Int
solve (m, c, p) = either id undefined $ go m 0 >>= go'
  where
    go :: [Int] -> Int -> Either Int [Int]
    go m acc
      | m == c = Left acc
      | acc == n = Right m
      | otherwise = go (substitute <$> m) (acc + 1)
    go' :: [Int] -> Either Int [Int]
    go' m =
      [(stepsTo substitute st nd, cycleSize substitute st) | (st, nd) <- zip m c]
        & gcrt
        & maybe undefined (Left . (+n) . fst)
    substitute x = p V.! (x-1)

cycleSize :: (Eq a) => (a -> a) -> a -> Int
cycleSize f x = 1 + stepsTo f (f x) x

stepsTo :: (Eq a) => (a -> a) -> a -> a -> Int
stepsTo f st nd = go 0 st
  where
    go acc x = if x == nd then acc else go (acc + 1) (f x)

gcrt :: [(Int, Int)] -> Maybe (Int, Int)
gcrt []         = Nothing
gcrt [e]        = Just e
gcrt (e1:e2:es) = gcrt2 e1 e2 >>= \e -> gcrt (e:es)

-- gcrt2 (a,n) (b,m) solves the pair of modular equations
--
--   x = a (mod n)
--   x = b (mod m)
--
-- It returns a pair (c, k) such that all solutions for x satisfy x =
-- c (mod k), that is, solutions are of the form x = kt + c for
-- integer t.
gcrt2 :: (Int, Int) -> (Int, Int) -> Maybe (Int, Int)
gcrt2 (a,n) (b,m)
  | a `mod` g == b `mod` g = Just (((a*v*m + b*u*n) `div` g) `mod` k, k)
  | otherwise              = Nothing
  where
    (g,u,v) = egcd n m
    k = (m*n) `div` g

-- egcd a b = (g,x,y)
--   g is the gcd of a and b, and ax + by = g
egcd :: Int -> Int -> (Int, Int, Int)
egcd a 0 = (abs a, signum a, 0)
egcd a b = (g, y, x - (a `div` b) * y)
  where
    (g,x,y) = egcd b (a `mod` b)
