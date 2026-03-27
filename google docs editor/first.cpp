#include <bits/stdc++.h>
using namespace std;


class DocumentEditor{
    public : 
        vector<string> elements;
        string rendered;

        void addText(string txt){
            elements.push_back(txt);
            cout<<"added the text to elements\n";
        }

        void addImage(string path){
            elements.push_back(path);
            cout<<"added the image to the elements\n";
        }

        string renderStrings(){
            if(!rendered.empty()) return rendered;
            string temp;
            for(const string ele : elements){
                if(ele.size()>4 && (ele.substr(ele.size()-4))==".png"){
                    temp += "Image : [ " + ele + "]\n";
                }else{
                    temp += ele + "\n";
                }
            }
            rendered = temp;
            return rendered;
        }

        void savetoDB(){
            ofstream file("resul.txt");
            if(file.is_open()){
                file << renderStrings();
                file.close();
                cout<<"Elements saved to db\n";
            }else{
                cout<<"Error opening the file\n";
            }
        }



};


int main()
{
    // DocumentEdtior* doc = new DocumentEditor();
    DocumentEditor doc;
    doc.addText("heyy i am the first line");
    doc.addImage("FirstImage.png");
    doc.addText("this is the new line , the latest one , check check");
    doc.savetoDB();
}