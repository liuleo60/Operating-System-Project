import sys

def main():
	output_f = open('conseq.txt', 'w')

	before = 'sum += ((long *)array)[';
	after = ']; ';
	for x in range(0, 128):
		output_f.write(before + str(x) + after)
		if x % 8 == 7:
			output_f.write('\n')

	before = 'sum += byte_array[';
	after = '];';
	for x in range(0, 1024):
		output_f.write(before + str(x) + after)
		if x % 8 == 7:
			output_f.write('\n')

	before = 'sum += int_array[';
	after = '];';
	for x in range(0, 1024):
		output_f.write(before + str(x) + after)
		if x % 8 == 7:
			output_f.write('\n')

	before = '((long *)array2)[';
	after = '] = 1; ';
	for x in range(0, 128):
		output_f.write(before + str(x) + after)
		if x % 8 == 7:
			output_f.write('\n')

	output_f.close();


if __name__ == "__main__":
    main ()