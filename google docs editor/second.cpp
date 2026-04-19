#include <bits/stdc++.h>
using namespace std;

// abstract class hai ye
class DocumentElement
{

public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement{

    private:
    string text;

    public : 
    TextElement(string s){
        this->text = s;
    }

    string render() override{
        return this->text;
    }



};


class ImageElement  : public DocumentElement{
    private : 
    string path;
    public  : 
    ImageElement(string path){
        this->path = path;
    }

    string render() override{
        string temp = "Image is : [" + this->path + "]\n";
        return temp;
    }
};

//now because we have made a interface called documentElement ,
// we can add and extend any kinds of documents and add it here without having to 
// write if else loops ovevr how to render it for each of them

//this is example of Open CLose principle of sOlid , here to add new features , we just have to extend and not 
//modify any existing code

class NewlineElement : public DocumentElement{
    public : 
    string render() override{
        return "\n";
    }
};

int main()
{   TextElement te("hello world");
    ImageElement imageElement("youtube.png");
    NewlineElement();
    cout<<"hello world";
}