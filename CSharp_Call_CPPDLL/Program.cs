using System;
using System.Runtime.InteropServices;

using CLRDLL;

public class Program
{

    public struct point
    {
        public double x;
        public double y;
        public point(double x_, double y_)
        {
            x = x_;
            y = y_;
        }
    };



    [DllImport("CPPDLL.dll", EntryPoint = "func1", SetLastError = true, CharSet = CharSet.Ansi)]
    public static extern unsafe void func1(int a, double b, char c, out int d,out double e, out char f);

    public static void test_func1()
    {
        int a = 1; double b = 2.2;char c = 'H';
        int d=0; double e=0; char f=' ';
        Console.WriteLine("[i n]C#  :"+a + "-" + b + "-" + c + "-" + d + "-" + e + "-" + f);
        func1(a, b, c, out d, out e, out f);
        Console.WriteLine("[out]C#  :" + a + "-" + b + "-" + c + "-" + d + "-" + e + "-" + f);
    }

    [DllImport("CPPDLL.dll", EntryPoint = "func2", SetLastError = true, CharSet = CharSet.Ansi)]
    public static extern unsafe void func2(int* a, int aNum,int* b,out IntPtr c, out int cNum,int[] d,int dNum);

    public static void test_func2()
    {
        int aNum = 3;
        int[] a=new int[aNum];
        for(int i=0;i<aNum;i++)
        {
            a[i] = i + 10;
        }

        int[] b = new int[2];
        int dNum = 3;
        int[] d = { 1, 2, 3 };

        int cNum = 0;
        unsafe
        {
            fixed (int* a_ptr = a)
            {
                fixed (int* b_ptr = b)
                {
                    IntPtr c;
                    func2(a_ptr, aNum, b_ptr, out c, out cNum,d,dNum);

                    Console.WriteLine("[out]C#/b:" + b[0]+","+b[1]);

                    int[] arr = new int[cNum];
                    Marshal.Copy(c, arr, 0, cNum);
                    for (int i = 0; i < cNum; i++)
                    {
                        Console.Write(arr[i] + "-");
                    }

                    Console.WriteLine("");
                    for (int i = 0; i < dNum; i++)
                    {
                        Console.Write(d[i] + "-");
                    }
                }

            }
        }
    }


    [DllImport("CPPDLL.dll", EntryPoint = "func3", SetLastError = true, CharSet = CharSet.Ansi)]
    public static extern unsafe void func3(point a,out point b);

    public static void test_func3()
    {
        point a=new point(1,2);
        Console.WriteLine("[in]C#/a:" + a.x + "," + a.y);

        point b;
        func3(a, out b);
        Console.WriteLine("[out]C#/b:" + b.x + "," + b.y);
    }


    [DllImport("CPPDLL.dll", EntryPoint = "func4", SetLastError = true, CharSet = CharSet.Ansi)]
    public static extern unsafe void func4(point* a, int aNum,point* b,int bNum);

    public static void test_func4()
    {
        point[] a =
        {
            new point(1,2),
            new point(3,4),
            new point(5,6)
        };
        int aNum = a.Length;

        int bNum = 2;
        point[] b = new point[bNum];

        unsafe
        {
            fixed(point* a_ptr=a)
            {
                fixed (point* b_ptr = b)
                {
                    func4(a_ptr, aNum, b_ptr, bNum);

                    for (int i = 0; i < bNum; i++)
                    {
                        Console.WriteLine(b[i].x + "," + b[i].y);
                    }
                }
            }
        }
    }



    [DllImport("CPPDLL.dll", EntryPoint = "func5", SetLastError = true, CharSet = CharSet.Ansi)]
    public static extern unsafe void func5(point** ployPoints, int ployNum, int* ployPointsNum);


    public static void Test_func5()
    {
        point[] abc = {
            new point(1.1,2.1),
            new point(3,4),
            new point(5,6.3)
        };
        point[] bcd = {
            new point(7,7.2),
            new point(8.5,8),
            new point(9.1,9),
            new point(10.1,11.9)
        };
        int[] length = { 3, 4 };

        unsafe
        {
            fixed (point* abc_ptr = abc)
            {
                fixed (point* bcd_ptr = bcd)
                {
                    fixed (int* length_ptr = length)
                    {
                        point*[] points = { abc_ptr, bcd_ptr };
                        fixed (point** points_ptr = points)
                        {
                            func5(points_ptr, length.Length, length_ptr);
                        }
                    }
                }
            }
        }
    }


    [DllImport("CPPDLL.dll", EntryPoint = "func6", SetLastError = true, CharSet = CharSet.Ansi)]
    public static extern unsafe void func6(point** ployPoints, int ployNum, int[] ployPointsNum);

    // C#申请第一层空间，C++申请第二层空间
    public static void Test_func6()
    {
        unsafe
        {
            int ployNum = 3;
            point*[] ployPointsList = new point*[ployNum];
            int[] ployPointsNum = new int[ployNum];
            fixed (point** ployPoints = ployPointsList)
            {
                func6(ployPoints, ployNum, ployPointsNum);
                Console.WriteLine(ployNum);
                for (int i = 0; i < ployNum; i++)
                {
                    for (int j = 0; j < ployPointsNum[i]; j++)
                    {
                        Console.WriteLine(ployPointsList[i][j].x + "," + ployPointsList[i][j].y);
                    }
                }
            }
        }
    }


    public static void Test_func7()
    {
        CLRDLL.ManegerClass manegerClass=new CLRDLL.ManegerClass();

        Console.WriteLine("-------------------------------");

        int a1 = 10;
        string str = "hello CLR";
        manegerClass.setA(a1, str);

        Console.WriteLine("-------------------------------");

        CLRDLL.point_ p = new CLRDLL.point_();
        p.x = 100;
        p.y = 200;
        manegerClass.setB(ref p);

        Console.WriteLine(string.Format("p(x,y):({0},{1})", p.x, p.y));

        Console.WriteLine("-------------------------------");

        int[] c =  { 5, 6, 7 };
        int num = c.Length;
        unsafe
        {
            fixed(int* c_=c)
            {
                manegerClass.setC(c_, num);
            }
        }

    }

    public static void Main()
    {
        //test_func1();
        //test_func2();
        //test_func3();
        //test_func4();
        //Test_func5();
        //Test_func6();
        Test_func7();
    }
}
