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
        string temp = "\nImage is : [" + this->path + "]\n";
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


class Document{

    private : 
    vector<DocumentElement*> docs;
    public : 

    
    string rendered;


    string render(){
        if(!rendered.empty()){
            return rendered;
        }else{
            for(const auto ele : docs){
                rendered+= ele->render();
            }
        }
        return rendered;
    }

    void addElement(DocumentElement* ele){
            docs.push_back(ele);
    }


};


class Persistence{

    public : 

    virtual void save(string text)=0;

};

class save2file : public Persistence{
    public :
    void save(string text){
        ofstream file("result2.txt");
            if(file.is_open()){
                file << text ;
                file.close();
                cout<<"Elements saved to db\n";
            }else{cout<<"Error opening the file\n";
            }
               
    }
};

class save2db : public Persistence{
    public : 
    void save(string text){
        cout<<"Saved the string : "<<text<<" into the Database.";
    }
};



class DocumentEditor{

    private : 
    Document* doc;
    string renderedString;
    Persistence* pers;
    public : 
    DocumentEditor(Document* d, Persistence* p){
        doc = d;
        pers = p;
    }
    void addText(string text){
        doc->addElement(new TextElement(text));
    }

    void addImage(string path){
        doc->addElement(new ImageElement(path));
    }

    void newLineElement(){
        doc->addElement(new NewlineElement());
    }

    string renderDocument(){
        if(renderedString.empty()) renderedString = doc->render();
        return renderedString;
    }

    void saveDocument(){
        pers->save(renderDocument());
    }

};

int main()
{   TextElement te("hello world");
    ImageElement imageElement("youtube.png");
    NewlineElement();
    cout<<"hello world";

    save2file fileSaver;
    Document newdoc;
    DocumentEditor de(&newdoc,&fileSaver);
    de.addText("This is the heading of this file");
    de.newLineElement();
    de.addText("THis must be the first line of myy paragraph in the db");
    de.addImage("in the onderive/images/src/ddcl/23");
    de.saveDocument();

    
}