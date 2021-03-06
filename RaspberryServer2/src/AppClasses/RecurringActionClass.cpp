#include "RecurringActionClass.h"

RecurringActionClass::RecurringActionClass(string _name, ActionButtonClass _recActActionButton, vector<long long> _recActDates, vector<long long> _recActTimes){
    this->recActName = _name;
    this->recActActionButton = _recActActionButton;
    this->recActDates = _recActDates;
    this->recActTimes = _recActTimes;
}
RecurringActionClass::RecurringActionClass(){}
RecurringActionClass::~RecurringActionClass(){}

bool RecurringActionClass::createFromJson(string json){
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(json);

    JsonArray& recActDatesArray = root["recActDates"];
    for (unsigned short i = 0; i < recActDatesArray.size(); i++){
	string str = recActDatesArray[i];
        long long date = atoll(str.c_str());
        this->recActDates.insert(this->recActDates.end(), date);
    }

    JsonArray& recActTimesArray = root["recActTimes"];
    for (unsigned short i = 0; i < recActTimesArray.size(); i++) {
        long long time = atoll(recActTimesArray[i]);
        this->recActTimes.insert(this->recActTimes.end(),time);
    }

    JsonObject& recActActionButton = root["recActActionButton"];
    string actionBtStr;
    recActActionButton.printTo(actionBtStr);
    this->recActActionButton = ActionButtonClass();

    const char* tmp = root["recActName"];
    if ((tmp == NULL) /*|| (tmp2 == NULL) || (tmp3 == NULL)*/) {
        return false;
    }
    this->recActName = string(tmp);
    this->recActActionButton.createFromJson(actionBtStr);


    return true;
}
string RecurringActionClass::parseToJson(){
    DynamicJsonBuffer rootBuffer, actionBuffer, recActTimesBuffer, recActDatesBuffer;
    JsonObject& root = rootBuffer.createObject();
//    JsonObject& actionObj = actionBuffer.createObject();
    JsonArray& recActTimesArray = recActTimesBuffer.createArray();
    JsonArray& recActDatesArray = recActDatesBuffer.createArray();


    string actionJson = this->recActActionButton.parseToJson();
    JsonObject& actionObj = actionBuffer.parseObject(actionJson);

    for (unsigned short i = 0; i < this->recActTimes.size(); i++){
        stringstream ss;
        ss << this->recActTimes.at(i);
        recActTimesArray.add(ss.str());
    }
    for (unsigned short i = 0; i < this->recActDates.size(); i++){
        stringstream ss;
        ss << this->recActDates.at(i);
        recActDatesArray.add(ss.str());
    }

    root["recActName"] = this->recActName;
    root["recActDates"] = recActDatesArray;
    root["recActTimes"] = recActTimesArray;
    root["recActActionButton"] = actionObj;


    string json;
    root.printTo(json);
    return json;

}

string RecurringActionClass::getRecActName(){return this->recActName;}
ActionButtonClass RecurringActionClass::getRecActActionButton(){ return this->recActActionButton;}
vector<long long> RecurringActionClass::getRecActDates(){return this->recActDates;}
vector<long long> RecurringActionClass::getRecActTimes(){return this->recActTimes;}



void RecurringActionClass::setRecActName(string name){this->recActName = name;};
void RecurringActionClass::setRecActActionButton(ActionButtonClass _actionButton){this->recActActionButton = _actionButton;};
void RecurringActionClass::setRecActDates(vector<long long> dates){this->recActDates = dates;};
void RecurringActionClass::setRecActTimes(vector<long long> times){this->recActTimes = times;};
