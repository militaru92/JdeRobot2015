module Message{

struct Num {
    long value;
};

interface Monitor {
    void publish2(Num m);
};

};
