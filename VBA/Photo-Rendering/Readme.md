# Photo Rendering

This little project is about rendering a photo to Excel's cells. Extracting colors per pixel of image and costumize cells color to match it. Collected colors of pixel assembled and build the image within cells.

## Features

- Customized resolution, but must match with image resolution itself.
- Pause and continue rendering.

## Issues known

- Error raised when customized cells interior are more than 65k different customizations. This restrict the resolution of the image for going too big.
- Cannot render image which not formatted as .jpg (Maybe because background transparency or something).

## Result

Here are some example result of this project.

![image1](https://user-images.githubusercontent.com/66581100/153751987-6ef1ea73-828f-46d5-9f29-a959ce936f6f.png)

This is not an inserted image, but a bunch of coloured cells as shown in the picture below.

![image2](https://user-images.githubusercontent.com/66581100/153752097-5b01a9fd-4555-42cb-a9cc-38c86518bfa5.png)

In the configuration panel, it looks like this:

![image](https://user-images.githubusercontent.com/66581100/153752149-413f840e-9baa-4618-9d82-4d7b757e3295.png)

So, what we can do is just specified the file name, and match the Height and Weight with the image size (in pixels).
- Start Render! will start converting the image from the start. The program will clear and rebuild the frame itself.
- Resume Render will start converting the image from the last time stopped, specified by the percentage completion value in the right.
- Stop Process will stop the process immediately, so we can resume the process later.

As Resume Render button will only resuming scan of the current stated picture (not the picture which stated beforehand), mix-match image is available to do.

## Compatibility

This program is created and tested with Microsoft Excel 2013 32-bit.

