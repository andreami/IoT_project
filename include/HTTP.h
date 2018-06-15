#ifndef HTTP_H
#define HTTP_H
#include <SFML/Network.hpp>


class HTTP
{
    public:
        HTTP();
        virtual ~HTTP();
        void turnOnLight(int idx);
        void turnOffLight(int idx);
        bool testConnection();

    protected:

    private:
        sf::Http http;
        sf::Http::Request request;
        sf::Http::Response response;
        void initLight();

};

#endif // HTTP_H
