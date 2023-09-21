class Matric {
private:
    int stolbec;
    int lines;
    int cols;
    double** matric;
    
public:
    Matric(const char *filename);
    ~Matric();
    void getElement(int a,int b);
    double** getMatric(double** buf);
    void removeMatric(double** buf);
    double* getStolbec(double** buf,int a);
    void removeStolbec(double* stolbic);
};