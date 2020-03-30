# iexplore Take-Over Protection
A program to stop Internet Explorer from ever opening.

## Why do you need this?
Simple. To stop programs that use Internet Explorer as a browser and not Windows' default set browser, this program does it for you.

## How to set it up?
Edit the file/create a file called `browser.cfg` and replace under `default` the "default" with any of the browsers listed below:

- `default` for Windows' set default browser
- `chrome` for Google Chrome
- `firefox` for Mozilla Firefox

Or any other browser, though this isn't supported. Just provide the exe of it to the arg.

Then, open up "Activate/Deactivate Windows Features" and deactivate Internet Explorer 11.

Now, some programs will simply say "iexplore.exe: Not found" when clicking links, this is where this program steps in.

Place the `iexplore.exe` and `browser.cfg` in C:\Windows\System32. It will now open everytime a program want's to open a link, and it'll autostart your browser of choice.