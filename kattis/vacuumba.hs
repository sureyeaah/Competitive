{-# LANGUAGE LambdaCase #-}
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
import           Control.Monad.State.Strict
import           Text.Printf

main :: IO ()
main = interact $
  parseInput >>> map solve >>> unlines

n :: Int
n = 100

parseInput :: String -> [[(Angle, Double)]]
parseInput = runScanner $ numberOf $ numberOf $ (,) . (\d -> d/180*pi) <$> double <*> double

type Coord = (Double, Double)
type Angle = Double

solve :: [(Angle, Double)] -> String
solve xs = let (x, y) = snd . foldl move (pi/2, (0, 0)) $ xs
             in printf "%.4f %.4f" x y

move :: (Angle, Coord) -> (Angle, Double) -> (Angle, Coord)
move (theta, (x, y)) (dTheta, dist) = let theta' = dTheta + theta
                                          x' = x + dist * cos theta'
                                          y' = y + dist * sin theta'
                                        in (theta', (x', y')) 
  
type Scanner = State [String]

runScanner :: Scanner a -> String -> a
runScanner s = evalState s . words

str :: Scanner String
str = get >>= \case { s:ss -> put ss >> return s }

int :: Scanner Int
int = read <$> str

integer :: Scanner Integer
integer = read <$> str

double :: Scanner Double
double = read <$> str

numberOf :: Scanner a -> Scanner [a]
numberOf s = int >>= flip replicateM s

many :: Scanner a -> Scanner [a]
many s = get >>= \case { [] -> return []; _ -> (:) <$> s <*> many s }
