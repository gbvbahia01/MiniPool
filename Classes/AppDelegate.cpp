#include "AppDelegate.h"


USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    pDirector->setOpenGLView(pEGLView);

    CCSize screenSize = pEGLView->getFrameSize();
    //CCSize designSize = CCSize(320, 480);
    std::vector<std::string> searchPaths;

    if (screenSize.width > 640) {
            searchPaths.push_back(largeResource.directory);
            pDirector->setContentScaleFactor(1280/designResolutionSize.height);
        }
	else if (screenSize.width > 320) {
            searchPaths.push_back(mediumResource.directory);
            pDirector->setContentScaleFactor(640/designResolutionSize.height);
	}else{
            searchPaths.push_back(smallResource.directory);
            pDirector->setContentScaleFactor(320/designResolutionSize.height);
        }
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designResolutionSize.height, designResolutionSize.width, kResolutionShowAll);
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);

    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("ball.ogg").c_str() );
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("drop.ogg").c_str() );
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("hit.ogg").c_str() );
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("whitedrop.ogg").c_str() );

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = GameLayer::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    //CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    //CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
