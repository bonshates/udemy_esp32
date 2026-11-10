ESP-IDF template app
====================

This is a template application to be used with [Espressif IoT Development Framework](https://github.com/espressif/esp-idf).

Please check [ESP-IDF docs](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for getting started instructions.
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
