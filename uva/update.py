import json, requests, fileinput

problems = "http://uhunt.felix-halim.net/api/cpbook/3"
userid = 858471
totalProblems = 0
totalSolved = 0
totalStarProblems = 0
totalStarSolved = 0
output = []
done = set()
f = open('readme.md', 'r')
for line in f:
	output.append(line)
	if "|:" in line:
			break
s = requests.get("http://uhunt.felix-halim.net/api/subs-user/{}".format(userid)).json()
r = requests.get(problems)
allProblems = requests.get('http://uhunt.felix-halim.net/api/p').json()

def getpid(pnum):
	for problem in allProblems:
		if problem[1] == pnum:
			return problem[0]

for chapter in r.json():
	chapterProblems = 0
	chapterProblemsSolved = 0
	chapterStarredProblems = 0
	chapterStarredSolved = 0
	for subChapter in chapter['arr']:
		for subSubChapter in subChapter['arr']:
			for problem in subSubChapter[1:]:
				chapterProblems = chapterProblems + 1
				if(problem < 0): chapterStarredProblems += 1
				pid = getpid(-problem)
				for submission in s['subs']:
					if submission[2] == 90 and submission[1] == pid:
						chapterProblemsSolved += 1
						if(problem < 0): chapterStarredSolved += 1
						if not pid in done:
							totalStarSolved += 1
							totalSolved += 1
						break
				if not pid in done:
					totalProblems += 1
					if(problem < 0): totalStarProblems += 1
					done.add(pid)
	output.append("|{}|{}%|{}%|\n".format(chapter['title'], int(chapterStarredSolved/chapterStarredProblems*100),int(chapterProblemsSolved/chapterProblems*100)))
	totalProblems += chapterProblems
	totalSolved += chapterProblemsSolved
f.close()
f = open('readme.md', 'w')
for line in output:
	f.write(line)
f.write("\nStarred Problems solved: **{}**/**{}**".format(totalStarSolved,totalStarProblems))