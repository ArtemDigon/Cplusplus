class Stringer{
private:
    void reverseWord(char* buf,int start, int end);
    char* string;
    int len; 
    

public:
    Stringer(const char* string);
    ~Stringer();
    void print();
    void reverseStrings();
    void newWords(const char* string);
    void reverseString();
    int countWords();

};