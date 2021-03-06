#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GLES-Render.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
	~HelloWorld();
	HelloWorld();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    void initPhysics();
    virtual void draw();
    void update(float dt);
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
private:
    b2World* world;
    GLESDebugDraw * m_debugDraw;

};

#endif // __HELLOWORLD_SCENE_H__
