#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Note: the names in this code use a number of standard prefixes, which you should know.  I've thrown
// in a few others in this list. They can be used with CamelCase or underscore_separated naming conventions.
//
//		min		minimum
//		max		maximum
//		avg		average
//		std		standard
//		temp	temporary (try not to use "temp" by itself as a variable name.  Say what the temporary holds.)
//		num		number of (when used as a prefix only.  Used as a suffix, it indicates an index or ID number.
//					       for example, numFiles is the number of files you have.  fileNum is the ID number
//						   of one particular file.)
//
//	Some people, notably people who learned to use C-style in C++, also use "in" as a prefix for "input", 
//  and "out" as a prefix for "output".  My preference is to not use these prefixes.
//
//  In general, except in the case of the standard prefixes, I advocate writing words out fully.  Don't use
//  "rng" for "range", for instance.  As another example, it would be disastrous to abbreviate "comparisons"
//  in the following main() function as "comp".  When the brain sees "comp" it has to sort out what that
//  means--it could be "computer" or "comprehensive" or "complete" or "computation", etc.--so writing it
//  out is essential.  Most of the comments in the code are meant to help out students and could be eliminated
//  in professional code.
//
//  Note that the correct specification of what a function may throw requires parentheses around the type, as
//  with writeArray() below.

class FileOpeningException {
private:
	string errorMessage;
public:
	FileOpeningException(string message) {
		errorMessage = message;
	}
	string getMessage() {
		return errorMessage;
	}
};

string* readWords(string filename, int & arraySize);
bool isInAlphabeticalOrder(string s);
float wordNumComp(string s);
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException);

int main (void) {
	int numWords;
	string wordListFilename = "./wordlist";
	string outputFilename = "average_comps.txt";

	// This reads the words from wordListFilename.
	// numWords will be the number of words in the array words
	// words[i] will be the ith word
	string *words = readWords(wordListFilename, numWords);


	// TO DO:: You can remove/comment out this.
	// Print out the list.
	/* 
	for (int i=0; i<numWords; i++) {
		cout << words[i] << endl;
	}
	*/


	// TO DO:: You should compute these values.
	float avgWordLength;
	float avgNumComparisons;
	int maxWordLength=0;  
	float *avgComparisonsForLength;  // avgComparisonsForLength[i] is the average number of comparisons for a word of length i.


	// TO DO:: Insert your code here.

	// Compute the average word length for the word list.
	avgWordLength = 0.0;
	float totalLength = 0.0;
	float totalNumComp = 0.0;
	float count_1 = 0.0;
	float count_2 = 0.0;
	for (int i=0; i<numWords; i++){
		// Find the max word length of the word list.
		if (maxWordLength < words[i].length()){
			maxWordLength = words[i].length();
		}
		totalLength += words[i].length();     // Add up words' length to total length.
		count_1 = wordNumComp(words[i]);
		totalNumComp += count_1;     // Add up word comparison number to total word comparison number.
	}

	avgWordLength = totalLength/numWords;      // Compute the average word length of word list.
	avgNumComparisons = totalNumComp/numWords;       // Compute the average number comparison of words.


	avgComparisonsForLength = new float[maxWordLength+1]{};      // Initializing the avgComparisonsForLength array.
	float *numLength = new float[maxWordLength+1]{};     // Initializing the numLength array.
	for (int i=0; i<numWords; i++){
		count_2 = wordNumComp(words[i]);
		avgComparisonsForLength[words[i].size()] += count_2;   // Add up each different length of words' comparison numbers to the average comparison length array.
		numLength[words[i].length()] ++;  // Word length increases by 1 for each iteration.
	}

	for (int i=1; i<maxWordLength+1; i++){
		avgComparisonsForLength[i] = avgComparisonsForLength[i] / numLength[i];  // Updating the average comparison for length array.
	}


	cout << "The average word length is: " << avgWordLength << endl;
	cout << "The average word comparison is: " << avgNumComparisons << endl;
	cout << "The maximum length of word is: " << maxWordLength << endl;

	// Print average number of comparisons for each length to a file for plotting.
	writeArray(outputFilename, avgComparisonsForLength, maxWordLength+1);


	//cout << "The average word comparison is " << avgNumComparisons << endl;
	// Clean up memory and return.
	delete[] words;
	delete[] numLength;
	delete[] avgComparisonsForLength;
	return 0;
}


// Writes the array arr in text format to a file named filename.
// each element of the array has its own line in the file, 
// which contains the element's index and value, separated by a space.
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException) {
	ofstream outputStream(filename.c_str());

	if (outputStream.fail()) {
		throw new FileOpeningException("Error opening " + filename);
	}
	for (int i = 1; i<arraySize; i++) {
		
		outputStream << i << " " << arr[i] << endl;
	}
	outputStream.close();
}

int numLinesInStream(ifstream& stream) {
	int numLines = 0;
	string tempLine;

	// getline returns 0 at end of file.
	while (getline(stream, tempLine)) {
		numLines++;
	}
	return numLines;
}

// note how the following function is all about one thing:
// the handling of the ifstream called inputStream().
// the exact computation done using inputStream() is abstracted
// to a single call (to numLinesInStream).
// Here, I don't declare the thrown object with a "throw ()" on the
// first line.  It's optional, so I'm leaving it off this time.
int numLinesInFile(string filename) {
	ifstream inputStream(filename.c_str());

	if (inputStream.fail()) {
		throw new FileOpeningException(filename + "... file not found ...");
	}

	int numLines = numLinesInStream(inputStream);

	inputStream.close();
	return numLines;
}

// Reads lines from a file named filename.
// Returns an array of strings, one per line of the file filename, 
// and places the size of the array in the reference parameter (output parameter) arraySize
string* readWords(string filename, int & arraySize) {
	string* result = NULL;
	arraySize = numLinesInFile(filename);
	ifstream inputStream(filename.c_str());

	// Read file contents into result, now that size is known
	result = new string[arraySize];			//create results array
	for (int i=0; i < arraySize; i++){
		getline(inputStream, result[i]);
	}
	inputStream.close(); //don't forget to close file

    return result;
}


bool isInAlphabeticalOrder(string s) {
	int length = s.size();
	for (int i = 0; i < length - 1; ++i) {
		if (s[i] > s[i+1]) {
			return false;
		}
	}
	return true;
}


// Return the average comparision numbers
float wordNumComp(string s){
	float length = s.size();
	float count = 0.0;
	for (int i = 0; i < length - 1; ++i){
		count ++;
		if (s[i] > s[i+1]){
			return count;
		}
	}
	return count;
}
