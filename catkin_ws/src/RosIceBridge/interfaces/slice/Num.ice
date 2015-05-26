module Message{

struct Num {
    long value;
};

interface Monitor {
    void publish(Num m);
};

};
