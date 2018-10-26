#pragma once
#include <unordered_map>

class InputManager
{
public:
    InputManager();
    ~InputManager();

    void update();

    void pressKey(unsigned int keyID);
    void releaseKey(unsigned int keyID);
    bool isKeyDown(unsigned int keyID);
    bool isKeyPressed(unsigned int keyID);

private:
    bool wasKeyDown(unsigned int keyID);

    std::unordered_map<unsigned int, bool> _keyMap;
    std::unordered_map<unsigned int, bool> _previousKeyMap;
};
