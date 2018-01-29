//
//  main.cpp
//  GradientTest
//
//  Created by Hossain, Rakeeb on 2018-01-02.
//  Copyright © 2018 Hossain, Rakeeb. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <dirent.h>

using namespace std;
using namespace cv;

enum SeverityScale
{
    MODERATETOLOW = 6,
    MODERATE,
    MODERATETOHIGH,
    HIGH,
    HIGHER,
    HIGHEST,
};

void makeFrameGradient(int lowerBound, int upperBound, string gradientFolder) {
    string lowerBoundGradientPath = gradientFolder + to_string(lowerBound) + ".jpg";
    string nextGradientPath = gradientFolder + to_string(lowerBound + 1) + ".jpg";
    string upperBoundGradientPath = gradientFolder + to_string(upperBound) + ".jpg";

    Mat frame1 = imread(lowerBoundGradientPath);
    Mat frame2 = imread(nextGradientPath);
    Mat frameFinal = imread(upperBoundGradientPath);
    Mat newFrame = frame1;
    bool seizureBool = true;
    int thresholdInt = 135;
    for (int count = 1; count <= 5; count++)
    {
        string pointPath = "/Users/232878/Desktop/Development/" + to_string(lowerBound + count) + ".jpg";
        for(int x = 0; x < frame1.rows; x++)
        {
            for(int y = 0; y < frame1.cols; y++)
            {
                Vec3b color1 = frame1.at<Vec3b>(x,y);
                Vec3b color2 = frame2.at<Vec3b>(x,y);
                Vec3b newColorFrame = newFrame.at<Vec3b>(x,y);

                if (color1[0] - color2[0] > thresholdInt)
                {
                    newColorFrame[0] = color1[0] - 10;
                }
                if (color2[0] - color1[0] > thresholdInt)
                {
                    newColorFrame[0] = color1[0] + thresholdInt;
                }
                if (color1[1] - color2[1] > thresholdInt)
                {
                    newColorFrame[1] = color1[1] - 10;

                }
                if (color2[1] - color1[1] > thresholdInt)
                {
                    newColorFrame[1] = color1[1] + 10;

                }
                if (color1[2] - color2[2] > thresholdInt)
                {
                    newColorFrame[2] = color1[2] - 10;
                }
                if (color2[2] - color1[2] > thresholdInt)
                {
                    newColorFrame[2] = color1[2] + 10;
                }
                newFrame.at<Vec3b>(x,y) = newColorFrame;
            }
        }
        frame1 = newFrame;
        imwrite(pointPath, newFrame);
        
        if (count == 5 && seizureBool == true)
        {
            lowerBound = lowerBound + count;
            lowerBoundGradientPath = gradientFolder + to_string(lowerBound) + ".jpg";
            nextGradientPath = gradientFolder + to_string(lowerBound + 1) + ".jpg";
            frame1 = imread(lowerBoundGradientPath);
            frame2 = imread(nextGradientPath);
            count = 0;
        }
        if (lowerBound + count == upperBound)
        {
            break;
        }
    }
}

vector< vector<float> > relativeLuminance(Mat colorFrame)
{
    vector< vector<float> > brightnessMatrix;
    brightnessMatrix.resize(colorFrame.rows);
    
    for (int x = 0; colorFrame.rows > x; x++)
    {
        brightnessMatrix[x].resize(colorFrame.cols);
        
        for (int y = 0; colorFrame.cols > y; y++)
        {
            Vec3b color = colorFrame.at<Vec3b>(x,y);
            int R = color[0];
            int G = color[1];
            int B = color[2];
            float Y = 0.2126*R + 0.7152*G + 0.0722*B;
            brightnessMatrix[x][y] = Y;
        }
    }
    return brightnessMatrix;
}


vector<vector<int > > seizureDetection(string path)
{
    
    int numOfFrames = 309;
    int n = 0;
    int seizureCount = 0;
    
    vector<vector<int > > seizureBoundaries(round(309.0/30.0), vector<int>(2));

    while(n + 30 < numOfFrames)
    {
        string path1 = path + to_string(n+1) + ".jpg";
        string path2 = path + to_string(n+2) + ".jpg";
        string path3 = path + to_string(n+3) + ".jpg";
        string path4 = path + to_string(n+4) + ".jpg";
        string path5 = path + to_string(n+5) + ".jpg";
        string path6 = path + to_string(n+6) + ".jpg";
        string path7 = path + to_string(n+7) + ".jpg";
        string path8 = path + to_string(n+8) + ".jpg";
        string path9 = path + to_string(n+9) + ".jpg";
        string path10 = path + to_string(n+10) + ".jpg";
        string path11 = path + to_string(n+11) + ".jpg";
        string path12 = path + to_string(n+12) + ".jpg";
        string path13 = path + to_string(n+13) + ".jpg";
        string path14 = path + to_string(n+14) + ".jpg";
        string path15 = path + to_string(n+15) + ".jpg";
        string path16 = path + to_string(n+16) + ".jpg";
        string path17 = path + to_string(n+17) + ".jpg";
        string path18 = path + to_string(n+18) + ".jpg";
        string path19 = path + to_string(n+19) + ".jpg";
        string path20 = path + to_string(n+20) + ".jpg";
        string path21 = path + to_string(n+21) + ".jpg";
        string path22 = path + to_string(n+22) + ".jpg";
        string path23 = path + to_string(n+23) + ".jpg";
        string path24 = path + to_string(n+24) + ".jpg";
        string path25 = path + to_string(n+25) + ".jpg";
        string path26 = path + to_string(n+26) + ".jpg";
        string path27 = path + to_string(n+27) + ".jpg";
        string path28 = path + to_string(n+28) + ".jpg";
        string path29 = path + to_string(n+29) + ".jpg";
        string path30 = path + to_string(n+30) + ".jpg";
        
        Mat frame1 = imread(path1);
        Mat frame2 = imread(path2);
        Mat frame3 = imread(path3);
        Mat frame4 = imread(path4);
        Mat frame5 = imread(path5);
        Mat frame6 = imread(path6);
        Mat frame7 = imread(path7);
        Mat frame8 = imread(path8);
        Mat frame9 = imread(path9);
        Mat frame10 = imread(path10);
        Mat frame11 = imread(path11);
        Mat frame12 = imread(path12);
        Mat frame13 = imread(path13);
        Mat frame14 = imread(path14);
        Mat frame15 = imread(path15);
        Mat frame16 = imread(path16);
        Mat frame17 = imread(path17);
        Mat frame18 = imread(path18);
        Mat frame19 = imread(path19);
        Mat frame20 = imread(path20);
        Mat frame21 = imread(path21);
        Mat frame22 = imread(path22);
        Mat frame23 = imread(path23);
        Mat frame24 = imread(path24);
        Mat frame25 = imread(path25);
        Mat frame26 = imread(path26);
        Mat frame27 = imread(path27);
        Mat frame28 = imread(path28);
        Mat frame29 = imread(path29);
        Mat frame30 = imread(path30);

        vector < vector<float> > frame1Luminance = relativeLuminance(frame1);
        vector < vector<float> > frame2Luminance = relativeLuminance(frame2);
        vector < vector<float> > frame3Luminance = relativeLuminance(frame3);
        vector < vector<float> > frame4Luminance = relativeLuminance(frame4);
        vector < vector<float> > frame5Luminance = relativeLuminance(frame5);
        vector < vector<float> > frame6Luminance = relativeLuminance(frame6);
        vector < vector<float> > frame7Luminance = relativeLuminance(frame7);
        vector < vector<float> > frame8Luminance = relativeLuminance(frame8);
        vector < vector<float> > frame9Luminance = relativeLuminance(frame9);
        vector < vector<float> > frame10Luminance = relativeLuminance(frame10);
        vector < vector<float> > frame11Luminance = relativeLuminance(frame11);
        vector < vector<float> > frame12Luminance = relativeLuminance(frame12);
        vector < vector<float> > frame13Luminance = relativeLuminance(frame13);
        vector < vector<float> > frame14Luminance = relativeLuminance(frame14);
        vector < vector<float> > frame15Luminance = relativeLuminance(frame15);
        vector < vector<float> > frame16Luminance = relativeLuminance(frame16);
        vector < vector<float> > frame17Luminance = relativeLuminance(frame17);
        vector < vector<float> > frame18Luminance = relativeLuminance(frame18);
        vector < vector<float> > frame19Luminance = relativeLuminance(frame19);
        vector < vector<float> > frame20Luminance = relativeLuminance(frame20);
        vector < vector<float> > frame21Luminance = relativeLuminance(frame21);
        vector < vector<float> > frame22Luminance = relativeLuminance(frame22);
        vector < vector<float> > frame23Luminance = relativeLuminance(frame23);
        vector < vector<float> > frame24Luminance = relativeLuminance(frame24);
        vector < vector<float> > frame25Luminance = relativeLuminance(frame25);
        vector < vector<float> > frame26Luminance = relativeLuminance(frame26);
        vector < vector<float> > frame27Luminance = relativeLuminance(frame27);
        vector < vector<float> > frame28Luminance = relativeLuminance(frame28);
        vector < vector<float> > frame29Luminance = relativeLuminance(frame29);
        vector < vector<float> > frame30Luminance = relativeLuminance(frame30);
        vector<vector<vector<float> > > luminanceMatrix {frame1Luminance, frame2Luminance, frame3Luminance, frame4Luminance, frame5Luminance, frame6Luminance, frame7Luminance, frame8Luminance, frame9Luminance, frame10Luminance, frame11Luminance, frame12Luminance, frame13Luminance, frame14Luminance, frame15Luminance, frame16Luminance, frame17Luminance, frame18Luminance, frame19Luminance, frame20Luminance, frame21Luminance, frame22Luminance, frame23Luminance, frame24Luminance, frame25Luminance, frame26Luminance, frame27Luminance, frame28Luminance, frame29Luminance, frame30Luminance};
        bool lookUp = false;
        bool lookDown = false;
        bool seizureBool;
        for (int x = 0; x < frame1.rows; x++)
        {
            for (int y = 0; y < frame1.cols; y++)
            {
                int flashCount = 0;
                int i = 1;
                int a = 0;
                do
                {
                    if ((luminanceMatrix[i][x][y] - luminanceMatrix[0][x][y])/(luminanceMatrix[0][x][y]) > 0.3 ) {
                        lookDown = true;
                        flashCount++;
                        a = i;
                    }
                    if ((luminanceMatrix[0][x][y] - luminanceMatrix[i][x][y])/(luminanceMatrix[i][x][y]) > 0.3 ) {
                        lookUp = true;
                        flashCount++;
                        a = i;
                    }
                    if (lookDown == true && lookUp == false)
                    {
                        if ((luminanceMatrix[a][x][y] - luminanceMatrix[i+1][x][y])/(luminanceMatrix[i+1][x][y]) > 0.3 )
                        {
                            flashCount++;
                            a = i+1;
                            lookDown = !lookDown;
                            lookUp = !lookUp;
                            goto skipIf;
                        }
                    }
                    if (lookUp == true && lookDown == false)
                    {
                        if ((luminanceMatrix[i+1][x][y] - luminanceMatrix[a][x][y])/(luminanceMatrix[a][x][y]) > 0.3 )
                        {
                            flashCount++;
                            a = i+1;
                            lookUp = !lookUp;
                            lookDown = !lookDown;
                        }
                    }
                skipIf:
                    i++;
                }
                while (i+1 < 30);
                
                if (lookUp == false && lookDown ==false)
                {
                    seizureBool = false;
                }

                if (flashCount >= 6)
                {
                    seizureBool = true;
                    seizureCount++;
                    /*
                    switch (flashCount)
                    {
                        case MODERATETOLOW:
                            cout << "Moderate to Low";
                            break;
                        case MODERATE:
                            cout << "Moderate";
                            break;
                        case MODERATETOHIGH:
                            cout << "Moderate to High";
                            break;
                        case HIGH:
                            cout << "High";
                            break;
                        case HIGHER:
                            cout << "HIGHER";
                            break;
                        case HIGHEST:
                            cout << "HIGHEST";
                            break;
                        default:
                            cout << "Error: Off the seizure scale!";
                    }
                     */
                }
            }
        }
        double portionOfScreen = 1.0*(seizureCount)/(frame1.rows*frame1.cols);
        if (portionOfScreen > 0.25)
        {
            seizureBoundaries[n/30][0] = n + 1;
            seizureBoundaries[n/30][1] = n + 30;
        }
        seizureCount = 0;
        n = n+30;
    }
    return seizureBoundaries;
}

int main(int argc, const char * argv[])
{
    vector<vector<int > > randMatrix = seizureDetection("/Users/232878/Desktop/Development/");
    
    for (int i = 0; i < randMatrix.size(); i++)
    {
        cout << randMatrix[i][0] << ", " << randMatrix[i][1] << endl;
    }
    // makeFrameGradient(80, 160, "/Users/232878/Desktop/Development/");
}