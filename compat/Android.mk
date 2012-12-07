BUILD_PAND := true
ifeq ($(BUILD_PAND),true)

LOCAL_PATH:= $(call my-dir)

#
# pand
#

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	pand.c bnep.c sdp.c

LOCAL_CFLAGS:= \
	-DVERSION=\"4.93\" -DSTORAGEDIR=\"/data/misc/bluetoothd\" -DNEED_PPOLL -D__ANDROID__

LOCAL_C_INCLUDES:=\
	$(LOCAL_PATH)/../lib \
	$(LOCAL_PATH)/../src \
	$(LOCAL_PATH)/../common \

LOCAL_SHARED_LIBRARIES := \
	libbluetoothd \
	libbluetooth \
	libcutils

LOCAL_MODULE_TAGS :=
LOCAL_MODULE:=pand

include $(BUILD_EXECUTABLE)
endif

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	../src/android_bluez.c \
	dun.c \
	dund.c \
	msdun.c \
	sdp.c

LOCAL_CFLAGS:= \
	-DVERSION=\"4.93\" \
	-DSTORAGEDIR=\"/data/misc/bluetoothd\" \
	-DCONFIGDIR=\"/etc/bluetooth\" \
	-DANDROID_BLUETOOTHDUN \
	-DANDROID_SET_AID_AND_CAP

LOCAL_C_INCLUDES:= \
	$(LOCAL_PATH)/../lib \
	$(LOCAL_PATH)/../gdbus \
	$(LOCAL_PATH)/../src \
	$(call include-path-for, glib) \
	$(call include-path-for, dbus)

LOCAL_SHARED_LIBRARIES := \
	libbluetooth \
	libglib \
	libdbus

LOCAL_STATIC_LIBRARIES := \
	libgdbus_static

LOCAL_MODULE_TAGS :=
LOCAL_MODULE:=dund

include $(BUILD_EXECUTABLE)
