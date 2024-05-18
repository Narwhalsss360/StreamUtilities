#include <StreamUtilities.h>

void setup()
{
    Serial.begin(115200);
    while (!Serial);
    Serial << "!!! Use LF (Line-Feed) line ending.\n";
}

void loop()
{
    Serial << "Enter words to form a sentence, enter '*STOP' to stop:\n";

    StringStream sentence;
    String word;

    sentence.str("[");

    while (true)
    {
        Serial >> word;

        if (word == "*STOP")
            break;

        if (sentence.str().length() != 1)
            sentence << ", ";

        sentence << word;
    }

    sentence << ']';
    Serial << '\n' << sentence.str() << endl;
}
