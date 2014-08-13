This performs anaylsis of two images and gives the value of `true postive`, `true negative`, `false positive`, `false negative`.

● True Positive (TP): TP with respect to foreground detection is identifying a foreground object as foreground. TP is identifying foreground pixels as foreground pixels.

● False Positive (FP): FP with respect to foreground detection is identifying a background object as foreground. This is a type of error.

● False Negative (FN): FN with respect to foreground detection is not identifying a foreground object as foreground. This is a type of error.

● True Negative (TN): TN with respect to foreground detection is not identifying a background object as foreground.

● Precision: The accuracy in identifying foreground pixels as foreground excluding FN and TN. Precision is defined as the ratio of TP to (TP + FP)

● Percentage of Wrong Classifications (PWC): PWC is defined as the ratio of (FN + FP) to (TP + FN + FP + TN) multiplied by 100

●Percentage of Right Classsifications (PRC): PRC is defined by 100-PWC

Note: The input images should be of type *.jpg only.

To execute:

`add opencv lib while compiling` and

`./a.out image1.jpg image2.jpg`
