using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OracleClient;
using System.Data;

namespace C_练习
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string cosn = "Data Source=172.20.65.236;User Id=bjmedicare_qy;Password=bjmedicare_qy";
            string sql = "select * from Users where account="+textBox1.Text;
            OracleConnection conn = new OracleConnection(cosn);
            OracleCommand cmd = new OracleCommand(sql, conn);
            OracleDataAdapter adp = new OracleDataAdapter(cmd);

            DataSet dsRet = new DataSet();
            adp.Fill(dsRet);
            adp.Dispose();
            conn.Close();
        }
    }
}
