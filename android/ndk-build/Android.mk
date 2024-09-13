LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm
LOCAL_MODULE := test
LOCAL_SRC_FILES := test.cxx
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -lc++

include $(BUILD_EXECUTABLE)