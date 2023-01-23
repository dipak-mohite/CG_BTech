#include <iostream>
#include <cmath>
#include <graphics.h>
using namespace std;

class translation
{

    int n, mat1[100], mat2[100], dx, dy, m, p, x, y, i, color, color2, tx, ty, pretrans[100][100], posttrans[100][100], j, trans[3][3], mat3[100], mat4[100], theta;
    float sx, sy;
    float rota[100][100], scale[100][100];

public:
    void getdata();
    void gettranslation();
    void getrotationdata();
    void getscalingdata();
    void showmatrixdata();
    void showmatrixdata2();
    void plotoriginaldata();
    void manipulatetranslationdata();
    void manipulaterotationdata();
    void manipulatescalingdata();
    void plottranslationdata();
    void bresline(int x1, int y1, int x2, int y2, int color);
};

void translation ::bresline(int x1, int y1, int x2, int y2, int color)
{

    dx = x2 - x1;
    dy = y2 - y1;
    if (dx != 0 && dy != 0)
        m = dy / dx;
    x = x1;
    y = y1;

    if (dx == 0)
    {
        while (y <= y2)
        {
            putpixel(x, y, color);
            y++;
        }
        while (y2 <= y)
        {
            putpixel(x2, y2, color);
            y2++;
        }
    }
    else if (dy == 0)
    {
        while (x <= x2)
        {
            putpixel(x, y, color);
            x++;
        }
        while (x2 <= x)
        {
            putpixel(x2, y2, color);
            x2++;
        }
    }
    else if (dx < 0)
    {
        if (dy < 0)
        {
            dx = abs(dx);
            dy = abs(dy);
            if (abs(m) < 1)
            {
                p = 2 * dy - dx;
                while (x >= x2)
                {
                    putpixel(x, y, color);
                    x--;
                    if (p < 0)
                    {
                        p += 2 * dy;
                    }
                    else
                    {
                        p += 2 * (dy - dx);
                        y--;
                    }
                }
            }
            else if (abs(m) > 1)
            {
                p = 2 * dx - dy;
                while (y >= y2)
                {
                    putpixel(x, y, color);
                    y--;
                    if (p < 0)
                    {
                        p += 2 * dx;
                    }
                    else
                    {
                        p += 2 * (dx - dy);
                        x--;
                    }
                }
            }
        }
        else if (dy > 0)
        {
            dx = abs(dx);
            if (abs(m) < 1)
            {
                p = 2 * dy - dx;
                while (y <= y2)
                {
                    putpixel(x, y, color);
                    x--;
                    if (p < 0)
                    {
                        p += 2 * dy;
                    }
                    else
                    {
                        p += 2 * (dy - dx);
                        y++;
                    }
                }
            }
            else if (abs(m) > 1)
            {
                p = 2 * dx - dy;
                while (y <= y2)
                {
                    putpixel(x, y, color);
                    y++;
                    if (p < 0)
                    {
                        p += 2 * dx;
                    }
                    else
                    {
                        p += 2 * (dx - dy);
                        x--;
                    }
                }
            }
        }
    }
    else if (dx > 0)
    {
        if (dy < 0)
        {
            dy = abs(dy);
            if (abs(m) < 1)
            {
                p = 2 * dy - dx;
                while (x <= x2)
                {
                    putpixel(x, y, color);
                    x++;
                    if (p < 0)
                    {
                        p += 2 * dy;
                    }
                    else
                    {
                        p += 2 * (dy - dx);
                        y--;
                    }
                }
            }
            else if (abs(m) > 1)
            {
                p = 2 * dx - dy;
                while (x <= x2)
                {
                    putpixel(x, y, color);
                    y--;
                    if (p < 0)
                    {
                        p += 2 * dx;
                    }
                    else
                    {
                        p += 2 * (dx - dy);
                        x++;
                    }
                }
            }
        }
        else if (dy > 0)
        {
            if (abs(m) < 1)
            {
                p = 2 * dy - dx;
                while (x <= x2)
                {
                    putpixel(x, y, color);
                    x++;
                    if (p < 0)
                    {
                        p += 2 * dy;
                    }
                    else
                    {
                        p += 2 * (dy - dx);
                        y++;
                    }
                }
            }
            else if (abs(m) > 1)
            {
                p = 2 * dx - dy;
                while (x <= x2)
                {
                    putpixel(x, y, color);
                    y++;
                    if (p < 0)
                    {
                        p += 2 * dx;
                    }
                    else
                    {
                        p += 2 * (dx - dy);
                        x++;
                    }
                }
            }
        }
    }
}

void translation ::getdata()
{
    cout << "Enter Number of Vertices: ";
    cin >> n;
    if (n > 2)
    {
        cout << "Enter Original Color: ";
        cin >> color;
        cout << "Enter Translated Color: ";
        cin >> color2;
        cout << "Enter Coordinates of Vertices: (NOTE: ALSO ENTER FIRST COORDINATE AT LAST)\n";

        for (i = 0; i <=+ n; i++)
        {
            cout << "X" << i << " = ";
            cin >> mat1[i];
            cout << "Y" << i << " = ";
            cin >> mat2[i];
        }
    }
    else
    {
        cout << "\nINVALID NUMBER OF VERTICES...\n";
    }
}

void translation ::gettranslation()
{
    cout << "Enter Values of Tx and Ty: ";
    cin >> tx >> ty;
}

void translation ::plotoriginaldata()
{
    setcolor(color);
    for (int i = 0; i < n; i++)
    {
        line(mat1[i] + 750, 375 - mat2[i], mat1[i + 1] + 750, 375 - mat2[i + 1]);
    }
}

void translation ::manipulatetranslationdata()
{
    for (int j = 0; j < n; j++)
    {
        pretrans[0][j] = mat1[j];
        pretrans[1][j] = mat2[j];
        pretrans[2][j] = 1;
    }
    for (int j = 0; j < 3; j++)

    {
        for (int i = 0; i < 3; i++)
        {
            if (j == i)
            {
                trans[j][i] = 1;
            }
            else
            {
                trans[j][i] = 0;
            }
        }
    }
    trans[0][2] = tx;
    trans[1][2] = ty;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            posttrans[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                posttrans[i][j] = posttrans[i][j] + (trans[i][k] * pretrans[k][j]);
            }
        }
    }
}

void translation ::showmatrixdata()
{
    cout << "Old Matrix: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << pretrans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Translation Matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "New Matrix After Multiplication: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << posttrans[i][j] << " ";
        }
        cout << endl;
    }
}

void translation ::showmatrixdata2()
{
    cout << "Old Matrix: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << pretrans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Rotation Matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << rota[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "New Matrix After Multiplication: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << posttrans[i][j] << " ";
        }
        cout << endl;
    }
}

void translation ::plottranslationdata()
{
    setcolor(color2);

    for (i = 0; i < n - 1; i++)
    {
        line(750 + posttrans[0][i], 375 - posttrans[1][i], 750 + posttrans[0][i + 1], 375 - posttrans[1][i + 1]);
    }

    line(750 + posttrans[0][n - 1], 375 - posttrans[1][n - 1], 750 + posttrans[0][0], 375 - posttrans[1][0]);
}

void translation ::getrotationdata()
{
    cout << "Enter Angle to which Figure to be Rotated: ";
    cin >> theta;
}

void translation ::manipulaterotationdata()
{
    for (int j = 0; j < n; j++)
    {
        pretrans[0][j] = mat1[j];
        pretrans[1][j] = mat2[j];
        pretrans[2][j] = 1;
    }
    for (int j = 0; j < 3; j++)

    {
        for (int i = 0; i < 3; i++)
        {
            if (j == i)
            {
                rota[j][i] = cos(theta * 3.142 / 180);
            }
            else
            {
                rota[j][i] = 0;
            }
        }
    }

    rota[2][2] = 1;
    rota[1][0] = sin(theta * 3.142 / 180);
    rota[0][1] = (-sin(theta * 3.142 / 180));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            posttrans[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                posttrans[i][j] = posttrans[i][j] + (rota[i][k] * pretrans[k][j]);
            }
        }
    }
}

void translation ::getscalingdata()
{
    cout << "Enter Values of Sx and  Sy: ";
    cin >> sx >> sy;
}

void translation ::manipulatescalingdata()
{
    for (int j = 0; j < n; j++)
    {
        pretrans[0][j] = mat1[j];
        pretrans[1][j] = mat2[j];
        pretrans[2][j] = 1;
    }
    for (int j = 0; j < 3; j++)

    {
        for (int i = 0; i < 3; i++)
        {
            if (j == i)
            {
                scale[j][i] = 1;
            }
            else
            {
                scale[j][i] = 0;
            }
        }
    }
    scale[0][0] = sx;
    scale[1][1] = sy;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            posttrans[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                posttrans[i][j] = posttrans[i][j] + (scale[i][k] * pretrans[k][j]);
            }
        }
    }
}

int main()
{
    translation z;
    initwindow(1500, 750, "2D TRASFORMATION");
    line(750, 0, 750, 750);
    line(0, 375, 1500, 375);

    int ch = 1;

    while (ch)
    {
        cout << "=== 2D Transformation ===" << endl;
        cout << "     1. Transformation" << endl;
        cout << "     2. Rotation" << endl;
        cout << "     3. Scaling" << endl;
        cout << "     0. Exit" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            exit(ch);
            break;

        case 1:

            z.getdata();
            z.gettranslation();
            z.manipulatetranslationdata();
            z.showmatrixdata();
            z.plotoriginaldata();
            z.plottranslationdata();
            break;

        case 2:

            z.getdata();
            z.getrotationdata();
            z.manipulaterotationdata();
            z.showmatrixdata2();
            z.plotoriginaldata();
            z.plottranslationdata();
            break;

        case 3:
            z.getdata();
            z.getscalingdata();
            z.manipulatescalingdata();
            z.plotoriginaldata();
            z.plottranslationdata();
            break;
        }
    }

    getch();
}
