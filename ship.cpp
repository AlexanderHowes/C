#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

std::string hexConversion(int in) {
	int r, i;
	std::string hexnum = "";
	std::string ret = "";
	std::string zero = "0";
	char hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (in > 0)
	{
		r = in % 16;
		hexnum = hex[r] + hexnum;
		in = in / 16;
	}
	r = 4 - hexnum.size();
	for (i = 0;i < r;i++) {
		ret.push_back(zero);
	}
	ret.push_back(hexnum);
	return ret;
}
std::string sicOut(char *key) {
	std::string out;
	out.append(key);
	out.append(".sic");
	return out;
}
std::string lisOut(char *key) {
	std::string out;
	out.append(key);
	out.append(".lis");
	return out;
}
void createOutputSic(std::vector<std::string> label,std::vector<std::string> instruction,std::vector<std::string> oper) {

	int i, j, len;
	std::string space(" ");
	std::vector<std::string> output;
	std::string hold;
	std::string smib;
	bool flag = true;

	for (i = 0;i < instruction.size();i++) {

		hold.append(label[i]);
		len = label[i].size();
		len = 8 - len;
		for (j = 0;j < len;j++) {
			hold.append(space);
		}
		//CHANGE make smib the function call to the e bit checker or the e bit vector (should be 4 digits)
		smib = ebit(i);
		if (smib[3] == 1) {
			hold.append("+");
		}
		if (smib[3] == 0) {
			hold.append(space);
		}

		hold.append(instruction[i]);
		len = instruction[i].size();
		len = 6 - len;
		for (j = 0;j < len;j++) {
			hold.append(space);
		}

		smib = nibit(i); // CHANGE make smib the function call to the ni bit checker or the ni bit vector
		if (smib == "01") {
			hold.append("#");
			flag = false;
		}
		if (smib == "10") {
			hold.append("@");
			flag = false;
		}
		if (flag == true) {
			hold.append(space);
		}
		flag = true;
		hold.append(oper[i]);
		smib = xbpecheck();
		len = oper[i].size();
		if (smib[0] == 1) {
			hold.append(",X");
			len = 7 - len;
			for (j = 0;j < len;j++) {
				hold.append(space);
			}
		}
		if (smib[1] == 0) {
			len = 9 - len;
			for (j = 0;j < len;j++) {
				hold.append(space);
			}
		}

		output.push_back(hold);
	}
	smib = sicOut(yourvariable);
	std::ofstream output_file(smib);
	std::ostream_iterator<std::string> output_iterator(output_file, "\n");
	std::copy(output.begin(), output.end(), output_iterator);
}
