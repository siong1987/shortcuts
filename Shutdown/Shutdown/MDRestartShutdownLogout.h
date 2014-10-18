// ref: http://stackoverflow.com/questions/6103962/perform-certain-system-events-mac-os-x/6105338#6105338

#import <CoreServices/CoreServices.h>

/*
 *    kAERestart        will cause system to restart
 *    kAEShutDown       will cause system to shutdown
 *    kAEReallyLogOut   will cause system to logout
 *    kAESleep          will cause system to sleep
 */
OSStatus MDSendAppleEventToSystemProcess(AEEventID eventToSendID) {
  AEAddressDesc targetDesc;
  static const ProcessSerialNumber kPSNOfSystemProcess = {0, kSystemProcess};
  AppleEvent eventReply = {typeNull, NULL};
  AppleEvent eventToSend = {typeNull, NULL};

  OSStatus status = AECreateDesc(typeProcessSerialNumber,
                                 &kPSNOfSystemProcess, sizeof(kPSNOfSystemProcess), &targetDesc);

  if (status != noErr) return status;

  status = AECreateAppleEvent(kCoreEventClass, eventToSendID,
                              &targetDesc, kAutoGenerateReturnID, kAnyTransactionID, &eventToSend);

  AEDisposeDesc(&targetDesc);

  if (status != noErr) return status;

  status = AESendMessage(&eventToSend, &eventReply,
                         kAENormalPriority, kAEDefaultTimeout);

  AEDisposeDesc(&eventToSend);
  if (status != noErr) return status;
  AEDisposeDesc(&eventReply);
  return status;
}