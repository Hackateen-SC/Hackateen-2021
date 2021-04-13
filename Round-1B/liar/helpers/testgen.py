import os, json, random

with open('test_data.json') as json_file:
	data = json.load(json_file)

	for i, case in enumerate(data, start=1):
		for j, test in enumerate(case['tests']):
			in_file_name = "tests/case{}/input{}.txt".format(i, j)
			in_file = open(in_file_name, "w")
			in_file.write("{}\n".format(str(test['N'])))
			arr = [random.randint(1, test['M']) for t in range(test['N'])]
			in_file.write("{}\n".format(" ".join([str(x) for x in arr])))
			st = [random.choice(['G', 'L']) for t in range(test['N'])]
			in_file.write("{}\n".format("".join(st)))
			in_file.close()
