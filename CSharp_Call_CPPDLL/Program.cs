using System;
using System.Runtime.InteropServices;


public class Program
{

    public struct Point
    {
        public double x;
        public double y;
        public Point(double x_, double y_)
        {
            x = x_;
            y = y_;
        }
    };


    [DllImport("CPPDLL.dll", EntryPoint = "ProcessPoints", SetLastError = true, CharSet = CharSet.Ansi)]
    public static extern unsafe void ProcessPoints(Point** points, int num_ploy, int* length);


    public static void Test_interface1()
    {
        Point[] abc = {
            new Point(1.1,2.1),
            new Point(3,4),
            new Point(5,6.3)
        };
        Point[] bcd = {
            new Point(7,7.2),
            new Point(8.5,8),
            new Point(9.1,9),
            new Point(10.1,11.9)
        };
        int[] length = { 3, 4 };

        unsafe
        {
            fixed (Point* abc_ptr = abc)
            {
                fixed (Point* bcd_ptr = bcd)
                {
                    fixed (int* length_ptr = length)
                    {
                        Point*[] points = { abc_ptr, bcd_ptr };
                        fixed (Point** points_ptr = points)
                        {
                            ProcessPoints(points_ptr, length.Length, length_ptr);
                        }
                    }
                }
            }
        }
    }


    [DllImport("CPPDLL.dll", EntryPoint = "ProcessPointsv2", SetLastError = true, CharSet = CharSet.Ansi)]
    public static extern unsafe void ProcessPointsv2(Point** ployPoints, int ployNum, int[] ployPointsNum);

    // C#申请第一层空间，C++申请第二层空间
    public static void Test_interface2()
    {
        unsafe
        {
            int ployNum = 3;
            Point*[] ployPointsList = new Point*[ployNum];
            int[] ployPointsNum = new int[ployNum];
            fixed (Point** ployPoints = ployPointsList)
            {
                ProcessPointsv2(ployPoints, ployNum, ployPointsNum);
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

    public static void Main()
    {
        // 结构、指针传递
        // C#的双重结构指针往C++传递数据
        //Test_interface1();
        // C#申请第一层结构空间，C++申请第二层结构指针空间
        Test_interface2();
    }
}
