using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Práctica_1_Team_Debian
{
    public partial class Form1 : Form
    {
        SerialPort puertoar;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            GraphicsPath path = new GraphicsPath();
            int radius = 20;

            path.StartFigure();
            path.AddArc(0, 0, radius * 2, radius * 2, 180, 90);
            path.AddLine(radius, 0, Width - radius, 0);
            path.AddArc(Width - radius * 2, 0, radius * 2, radius * 2, 270, 90);
            path.AddLine(Width, radius, Width, Height - radius);
            path.AddArc(Width - radius * 2, Height - radius * 2, radius * 2, radius * 2, 0, 90);
            path.AddLine(Width - radius, Height, radius, Height);
            path.AddArc(0, Height - radius * 2, radius * 2, radius * 2, 90, 90);
            path.AddLine(0, Height - radius, 0, radius);
            path.CloseFigure();

            this.Region = new Region(path);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            puertoar = new SerialPort();
            puertoar.PortName = "COM6";
            puertoar.BaudRate = 115200;
            puertoar.DtrEnable = true;
            try
            {
                puertoar.Open();
                MessageBox.Show("Sí se conectó :)");
            }
            catch (Exception ex)
            {
                MessageBox.Show("No está conectado" + ex);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                puertoar.WriteLine(textBox1.ToString());
                MessageBox.Show("Se envio correctamente");
            }
            catch (Exception ex)
            {
                MessageBox.Show("No se envió" + ex);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
