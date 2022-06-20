#include <AL/al.h>
#include <AL/alc.h>
#include <stdio.h>
#include <stdlib.h>

/* Compile with: gcc -Wall openal.c -o oal -lopenal */

int main(int argc, char *argv[]) {
  const ALCchar *defaultDeviceName =
      alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
  if (defaultDeviceName == NULL) {
    fprintf(stderr, "Cannot find OpenAL default device.\n");
    exit(1);
  }
  ALCdevice *defaultDevice = alcOpenDevice(defaultDeviceName);
  if (defaultDevice == NULL) {
    fprintf(stderr, "Cannot initialize OpenAL default device '%s'",
            defaultDeviceName);
    exit(1);
  }
  ALCcontext *context = alcCreateContext(defaultDevice, NULL);
  if (context == NULL) {
    fprintf(stderr, "Cannot create OpenAL context\n");
    exit(1);
  }
  if (alcMakeContextCurrent(context) == ALC_FALSE) {
    fprintf(stderr, "Cannot make OpenAL current context\n");
    exit(1);
  }
  printf("OpenAL initialization successful\n");
  return 0;
}
