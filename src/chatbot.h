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
    wxBitmap *_image; // avatar image

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

    ChatBot(int v);

    //// STUDENT CODE
    ////
    //ChatBot(const ChatBot &source);    // Copy Constructor
    ChatBot(const ChatBot &source)             // Constructor
    {
        std::cout << "ChatBot Copy Constructor" << std::endl;

        _image = source._image;
        _currentNode = source._currentNode;
        _chatLogic = source._chatLogic;
        _rootNode = source._rootNode;
        
    }
    
    ChatBot &operator=(const ChatBot &source)
    {
        std::cout << "ChatBot Copy Assignment Operator" << std::endl;
        if (this == &source) return *this;

        //delete _image;

        _image = source._image;
        _currentNode = source._currentNode;
        _chatLogic = source._chatLogic;
        _rootNode = source._rootNode;


        return *this;
    }


    ChatBot(ChatBot &&source)
    {
        std::cout << "ChatBot Move Constructor" << std::endl;

        _image = source._image;
        _currentNode = source._currentNode;
        _rootNode = source._rootNode;
        _chatLogic = source._chatLogic;

        source._image = NULL;
        source._currentNode = nullptr;
        source._rootNode = nullptr;
        source._chatLogic = nullptr;
    }

    ChatBot &operator=(ChatBot &&source)
    {
        std::cout << "ChatBot Move Assignment Operator" << std::endl;
        if (this == &source) return *this;

        _image = source._image;
        _currentNode = source._currentNode;
        _chatLogic = source._chatLogic;
        _rootNode = source._rootNode;

        source._image = NULL; 
        source._currentNode = nullptr;
        source._chatLogic = nullptr;
        source._rootNode = nullptr;


    }

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */