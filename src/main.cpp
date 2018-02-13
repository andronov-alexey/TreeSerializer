#include <iostream>
#include <fstream>

#include "tree/deserializers/TreeDeserializer.h"
#include "tree/serializers/TreeSerializer.h"

#include "TreeDrawer.h"
#include "OptionsReader.h"
#include "FormatConfig.h"

using namespace std;

int main(int _argc, char * _argv[]) {
	// skip app name
	OptionsReader optsReader{ &_argv[1], _argc - 1 };

	const string inputFileName = optsReader.getValue("-i");
	const string outputFileName = optsReader.getValue("-o");

	if (inputFileName.empty() || outputFileName.empty()) {
		cerr << "Error: wrong arguments format\n"
			<< "Usage: " << _argv[0] << " -i <inputfile> -o <outputfile>\n"
			<< "Press <enter> to exit ..." << endl;
		getchar();
		return 1;
	}

	ifstream inputStream{ inputFileName };
	ofstream outputStream{ outputFileName };
	TreeDrawer treeDrawer;

	if (inputStream) {
		TreeDeserializer treeDeserializer(FormatConfig::FILE_TOKENS_DELIMETER);
		TreeSerializer treeSerializer(FormatConfig::FILE_TOKENS_DELIMETER);
		string rawData;

		while (getline(inputStream, rawData)) {
			shared_ptr<Node> tree = treeDeserializer.deserialize(rawData);

			if (tree->isValid()) {
				treeDrawer.draw(tree);

				string newRawData = treeSerializer.serialize(tree);
				outputStream << newRawData << endl;
			} else {
				cerr << "Tree in file is malformed, please, make sure you use appropriate format" << endl;
			}
		}
	}

	outputStream.close();
	inputStream.close();

	cout << "Done. Results written to file: \"" << outputFileName << "\"" << endl;
	cout << "Press <enter> to exit ..." << endl;
	getchar();

	return 0;
}
