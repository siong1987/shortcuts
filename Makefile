
APPS = Lock Logout Restart Shutdown Sleep

APP = $(shell basename $@ .app)

NOSIGN = CODE_SIGN_IDENTITY=
TARGET = TARGET_BUILD_DIR=$(CURDIR)
DDPATH = -derivedDataPath /tmp 
XCODEB = xcodebuild $(DDPATH) $(NOSIGN) $(TARGET) $(DEPLOY) -scheme

all : $(addsuffix .app, $(APPS))

%.app :
	$(XCODEB) $(APP) -project $(APP)/$(APP).xcodeproj 1> /dev/null
	
clean :
	rm -rf *.app
