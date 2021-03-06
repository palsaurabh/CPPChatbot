#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>
class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    // std::unique_ptr<wxBitmap> _image; // avatar image
    wxBitmap * _image;

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    ChatBot(ChatBot &&source);       //Move constructor

    //Copy constructor
    ChatBot(const ChatBot &source);

    ChatBot &operator=(const ChatBot &source); // 3 : copy assignment operator
    
    ChatBot &operator=(ChatBot &&source); // 5 : move assignment operator

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() {    
        if(_image == NULL)
            std::cout<<"Inside GetImageHandle is  NULL"<<'\n';

         return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
