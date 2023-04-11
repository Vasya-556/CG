using System;
using System.Drawing;
using System.Windows.Forms;
using System.Windows.Media.Media3D;

namespace Lab_3_graph
{
    public partial class Form1 : Form
    {
        readonly int N = 7;
        readonly double R = 125;

        double alpha = 0;
        double beta = 0;
        double gamma = 0;

        void ReCalculateFigure()
        {
            Bitmap bmp = new Bitmap(pB.Width, pB.Height);
            Graphics helper = Graphics.FromImage(bmp);

            Point3D O = new Point3D() { X = 0, Y = 0, Z = 0 };
            Point3D Camera = new Point3D() { X = 150, Y = 140, Z = 100 };

            double Fi = 360 / 2 * N;
            Point3D[] figure = new Point3D[N * 2 + 1];

            //creating empty points
            for (int i = 0; i < N * 2 + 1; i++)
                figure[i] = new Point3D();

            //filling figure with coords
            for (int i = 0; i < N; i++)
            {
                figure[i].X = O.X + (int)((R) * Math.Cos(Fi + (2 * Math.PI * i) / N));
                figure[i].Y = O.Y + (int)((R) * Math.Sin(Fi + (2 * Math.PI * i) / N));
                figure[i].Z = O.Z;
            }


            figure[figure.Length - 1].X = O.X;
            figure[figure.Length - 1].Y = O.Y;
            double H = 170; // height
            figure[figure.Length - 1].Z = O.Z + H + 50;


            RotationMatrix_X(figure, Camera, N, gamma);
            RotationMatrix_Y(figure, Camera, N, beta);
            RotationMatrix_Z(figure, Camera, N, alpha);

            transplantationMatrix(figure, Camera, N);
            mirrorMatrix(figure, N);
            paralelScene(figure, N);
            printFigure(figure, N, helper);
            pB.Image = bmp;
        }

        private void printFigure(Point3D[] figure, int N, Graphics g)
        {
            Pen pen = new Pen(Color.Black, 2);



            for (int i = N + 1; i < N * 2; i++)
            {
                g.DrawLine(pen, (int)figure[i - N].Y, (int)figure[i - N].Z, (int)figure[N * 2].Y, (int)figure[N * 2].Z);
            }
            for (int i = 0; i < N - 1; i++)
            {
                g.DrawLine(pen, (int)figure[i].Y, (int)figure[i].Z, (int)figure[i + 1].Y, (int)figure[i + 1].Z);
            }
            g.DrawLine(pen, (int)figure[N - 1].Y, (int)figure[N - 1].Z, (int)figure[0].Y, (int)figure[0].Z);

        }

        private void RotationMatrix_X(Point3D[] figure, Point3D Camera, int N, double a)
        {

            double tmpY;

            for (int i = 0; i < N * 2 + 1; i++)
            {
                tmpY = figure[i].Y;
                figure[i].Y = tmpY * Math.Cos(a) - figure[i].Z * Math.Sin(a);
                figure[i].Z = tmpY * Math.Sin(a) + figure[i].Z * Math.Cos(a);
            }
        }


        private void RotationMatrix_Y(Point3D[] figure, Point3D Camera, int N, double a)
        {
            double tmpX;

            for (int i = 0; i < N * 2 + 1; i++)
            {
                tmpX = figure[i].X;
                figure[i].X = tmpX * Math.Cos(a * 180 / Math.PI) + figure[i].Z * Math.Sin(a * 180 / Math.PI);
                figure[i].Z = -tmpX * Math.Sin(a * 180 / Math.PI) + figure[i].Z * Math.Cos(a * 180 / Math.PI);
            }
        }

        private void RotationMatrix_Z(Point3D[] figure, Point3D Camera, int N, double a)
        {
            double tmpX;

            for (int i = 0; i < N * 2 + 1; i++)
            {
                tmpX = figure[i].X;
                figure[i].X = tmpX * Math.Cos((a * 180) / Math.PI) - figure[i].Y * Math.Sin((a * 180) / Math.PI);
                figure[i].Y = tmpX * Math.Sin((a * 180) / Math.PI) + figure[i].Y * Math.Cos((a * 180) / Math.PI);
            }
        }

        private void paralelScene(Point3D[] figure, int N)
        {
            for (int i = 0; i < N * 2 + 1; i++)
            {
                figure[i].Y += pB.Width / 2;
                figure[i].Z += pB.Height / 2;
            }
        }

        private void perspectiveScene(Point3D[] figure, int N, double d)
        {
            for (int i = 0; i < N * 2 + 1; i++)
            {
                figure[i].Y += d * figure[i].Y / figure[i].X;
                figure[i].Z += d * figure[i].Z / figure[i].X;
            }

            for (int i = 0; i < N * 2 + 1; i++)
            {
                figure[i].Y = figure[i].Y + pB.Width / 2;
                figure[i].Z = pB.Height / 2 - figure[i].Z;
            }
        }


        private void transplantationMatrix(Point3D[] figure, Point3D Camera, int N)
        {
            double p = Math.Sqrt(Math.Pow(Camera.X, 2) + Math.Pow(Camera.Y, 2) + Math.Pow(Camera.Z, 2));
            for (int i = 0; i < N * 2 + 1; i++)
                figure[i].X -= p;
        }

        private void mirrorMatrix(Point3D[] figure, int N)
        {
            for (int i = 0; i < N * 2 + 1; i++)
                figure[i].X *= -1;
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ReCalculateFigure();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            gamma += 0.1;
            ReCalculateFigure();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            gamma -= 0.1;
            ReCalculateFigure();

        }

        private void button3_Click(object sender, EventArgs e)
        {
            beta += 0.1;
            ReCalculateFigure();

        }

        private void button4_Click(object sender, EventArgs e)
        {
            beta -= 0.1;
            ReCalculateFigure();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            alpha += 0.1;
            ReCalculateFigure();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            alpha -= 0.1;
            ReCalculateFigure();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
