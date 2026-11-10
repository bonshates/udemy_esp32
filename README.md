ESP-IDF template app
====================

This is a template application to be used with [Espressif IoT Development Framework](https://github.com/espressif/esp-idf).

Please check [ESP-IDF docs](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for getting started instructions.

## Build, flash, and verify runtime execution

The application logs `Main loop running` at INFO level with the tag `main`
on each loop iteration, followed by a 300 ms FreeRTOS delay.

### Verification steps

1. Connect the ESP32 and ensure its USB serial adapter is attached to the VM
   when using VirtualBox. Confirm that `/dev/ttyUSB0` is readable and writable.
   Substitute the actual serial device path if different.
2. Stop or disconnect any IDE serial monitor before flashing. Only one process
   should access the port; `fuser -v /dev/ttyUSB0` can identify its current owner.
3. Activate ESP-IDF v5.4.1 by sourcing its `export.sh`. On the verified local
   setup, run `source /home/sean/esp-idf-v5.4.1/export.sh`.
4. From the project directory, run `idf.py build`, followed by
   `idf.py -p /dev/ttyUSB0 flash`. Confirm that flashing completes and reports
   `Hash of data verified` for the written images.
5. Run `idf.py -p /dev/ttyUSB0 monitor` at the configured 115200 baud.
   If needed, press Ctrl+T followed by Ctrl+R to reset the board and observe
   a fresh boot.
6. Confirm that startup reaches `Calling app_main()` and repeatedly prints
   `main: Main loop running`. Compare successive log timestamps: they should
   be approximately 300 ms apart. Observe for at least 10 seconds and check
   for panics, watchdog failures, brownouts, or unexpected repeated boots.
7. Exit the monitor with Ctrl+] to release the serial port.

### Recorded verification (2026-11-10)

- ESP-IDF v5.4.1 build completed successfully for ESP32.
- Flashing to an ESP32-D0WD-V3 revision v3.1 via `/dev/ttyUSB0` completed;
  all written images passed hash verification.
- A bounded serial capture at 115200 baud observed 33 `Main loop running`
  messages over approximately 10 seconds. Successive device timestamps were
  consistently 300 ms apart.
- No panic, watchdog, or brownout messages were detected during that capture.
  Initial serial data was garbled before the readable boot log; this was
  not a long-duration stability test.
- The serial connection was closed after verification.
## Troubleshooting: C files show an Error editor tab

**Status:** Closed with a user-verified workaround (2026-11-10). The underlying
IDE defect has not been confirmed fixed.

In Espressif IDE, opening a C file may show only an `Error` tab. The Generic
Code Editor also previously reported a `NullPointerException` in
`InlinedAnnotationSupport$VisibleLines.install` because
`ISourceViewer.getDocument()` returned null. The plain Text Editor could open
the file.

### Verified workaround

1. Right-click the C file in Project Explorer.
2. Select **Open With → Generic Code Editor**.
3. Confirm that the source opens correctly.

To use this editor by default, open **Window → Preferences → General →
Editors → File Associations**, select `*.c`, select **Generic Code Editor**
under associated editors, click **Default**, then **Apply and Close**.

The **Show code minings for problem annotations** preference under **General →
Editors → Text Editors** was already set to **None** during troubleshooting.
It was applied again, but disabling code mining was not established as the
cause of recovery.

A matching Eclipse exception is tracked in
[Eclipse Platform UI issue #3068](https://github.com/eclipse-platform/eclipse.platform.ui/issues/3068).
This project note does not imply that the upstream defect is fixed.

*Code in this repository is in the Public Domain (or CC0 licensed, at your option.)
Unless required by applicable law or agreed to in writing, this
software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied.*
