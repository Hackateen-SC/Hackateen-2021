import os, json, random

with open('test_data.json') as json_file:
	data = json.load(json_file)

	for i, case in enumerate(data, start=1):
		for j, test in enumerate(case['tests']):
			in_file_name = "tests/case{}/input{}.txt".format(i, j)
			out_file_name = "tests/case{}/output{}.txt".format(i, j)
			os.system("./sol < {} > {}".format(in_file_name, out_file_name))