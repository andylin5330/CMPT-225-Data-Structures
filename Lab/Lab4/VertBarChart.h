#include <iostream>
#include <string>
#include "VectorGraph.h"
#include "BarChart.h"

using namespace std;

class VertBarChart : public BarChart{
public:
    virtual void setN(int n){
        size = n;
    }			// sets the number of data items
    virtual void setData(int* data){
        this->data = data;
    }		// sets the data array.
    virtual void setLabels(string* labels){
        this->labels = labels;
    }	// sets the label array.
    virtual void setScale(int scale){
        this->scale = scale;
    }		// sets how many units in data = one character
    virtual void draw(){
        vector<int> vecData(data, data+size);
        vector<string> vecLabels(labels, labels+size);
        VectorGraph temp(vecData,vecLabels,scale);
        temp.draw(std::cout);
    }			// draws the bar chart to cout


private:
    int size;
    int* data;
    string* labels;
    int scale;
};

