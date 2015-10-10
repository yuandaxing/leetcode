import sys
import random
def sample(P):
	cum = 0
	r = random.random()
	for i in range(0,len(P)):
		cum = cum + P[i]
		if r < cum:
			return i
P=[0.2,0.3,0.3,0.2]
s = {}
for i in range(0,1000000):
	samp = sample(P)
	if s.has_key(samp):
		s[samp] = s[samp] + 1
	else:
		s[samp] = 0
print s
