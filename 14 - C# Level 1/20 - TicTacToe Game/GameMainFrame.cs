using _20___TicTacToe_Game.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _20___TicTacToe_Game
{
    public partial class GameMainFrame : Form
    {
        enum enPlayers
        {
            PlayerX = 0,
            PlayerO = 1
        }
        enum enGameStatus
        {
            InProgress = 0,
            Tie = 1,
            PlayerXWin = 2,
            PlayerOWin = 3
        }

        enPlayers currentPlayer;
        enGameStatus gameStatus;
        byte occupiedPositions;

        public GameMainFrame()
        {
            InitializeComponent();
            occupiedPositions = 0;
        }

        private void GameMainFrame_Paint(object sender, PaintEventArgs e)
        {
            Pen pen = new Pen(Color.White);

            pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            pen.Width = 10;

            // Draw Horizontal Lines
            e.Graphics.DrawLine(pen, 340, 300, 940, 300);
            e.Graphics.DrawLine(pen, 340, 500, 940, 500);

            // Draw Vertical Lines
            e.Graphics.DrawLine(pen, 525, 125, 525, 675);
            e.Graphics.DrawLine(pen, 775, 125, 775, 675);
        }

        private void SwitchTurn()
        {
            currentPlayer = (enPlayers)((int)currentPlayer ^ 1);
        }

        private void UpdateTurnLabel()
        {
            if (currentPlayer == enPlayers.PlayerX)
                LblPlayerTurn.Text = "Player X";
            else
                LblPlayerTurn.Text = "Player O";
        }

        private void UpdateGameStatus()
        {
            UpdateTurnLabel();
            
            if (gameStatus == enGameStatus.InProgress)
            {
                LblGameWinner.Text = "In Progress";
                return;
            }

            if (gameStatus == enGameStatus.Tie)
            {
                LblGameWinner.Text = "Tie";
                return;
            }

            if (gameStatus == enGameStatus.PlayerXWin)
            {
                LblGameWinner.Text = "Player X";
                return;
            }
            else
                LblGameWinner.Text = "Player O";
        }

        private bool CheckHorizontal()
        {
            if (BoardPosition1.Tag != null && BoardPosition2.Tag != null && BoardPosition3.Tag != null)
            {
                if (BoardPosition1.Tag.ToString() == BoardPosition2.Tag.ToString() &&
                    BoardPosition2.Tag.ToString() == BoardPosition3.Tag.ToString())
                {
                    return true;
                }
            }

            if (BoardPosition4.Tag != null && BoardPosition5.Tag != null && BoardPosition6.Tag != null)
            {
                if (BoardPosition4.Tag.ToString() == BoardPosition5.Tag.ToString() &&
                    BoardPosition5.Tag.ToString() == BoardPosition6.Tag.ToString())
                {
                    return true;
                }
            }

            if (BoardPosition7.Tag != null && BoardPosition8.Tag != null && BoardPosition9.Tag != null)
            {
                if (BoardPosition7.Tag.ToString() == BoardPosition8.Tag.ToString() &&
                    BoardPosition8.Tag.ToString() == BoardPosition9.Tag.ToString())
                {
                    return true;
                }
            }

            return false;

        }

        private bool CheckVertical()
        {
            if (BoardPosition1.Tag != null && BoardPosition4.Tag != null && BoardPosition7.Tag != null)
            {
                if (BoardPosition1.Tag.ToString() == BoardPosition4.Tag.ToString() &&
                    BoardPosition4.Tag.ToString() == BoardPosition7.Tag.ToString())
                {
                    return true;
                }
            }

            if (BoardPosition2.Tag != null && BoardPosition5.Tag != null && BoardPosition8.Tag != null)
            {
                if (BoardPosition2.Tag.ToString() == BoardPosition5.Tag.ToString() &&
                    BoardPosition5.Tag.ToString() == BoardPosition8.Tag.ToString())
                {
                    return true;
                }
            }

            if (BoardPosition3.Tag != null && BoardPosition6.Tag != null && BoardPosition9.Tag != null)
            {
                if (BoardPosition3.Tag.ToString() == BoardPosition6.Tag.ToString() &&
                    BoardPosition6.Tag.ToString() == BoardPosition9.Tag.ToString())
                {
                    return true;
                }
            }

            return false;
        }

        private bool CheckDiagonal()
        {
            if (BoardPosition1.Tag != null && BoardPosition5.Tag != null && BoardPosition9.Tag != null)
            {
                if (BoardPosition1.Tag.ToString() == BoardPosition5.Tag.ToString() &&
                    BoardPosition5.Tag.ToString() == BoardPosition9.Tag.ToString())
                {
                    return true;
                }
            }

            if (BoardPosition3.Tag != null && BoardPosition5.Tag != null && BoardPosition7.Tag != null)
            {
                if (BoardPosition3.Tag.ToString() == BoardPosition5.Tag.ToString() &&
                    BoardPosition5.Tag.ToString() == BoardPosition7.Tag.ToString())
                {
                    return true;
                }
            }

            return false;
        }

        private bool IsGameFinished()
        {
            if (occupiedPositions == 9)
            {
                gameStatus = enGameStatus.Tie;
                return true;
            }

            else if (CheckHorizontal())
            {
                gameStatus = (currentPlayer == enPlayers.PlayerX) ? enGameStatus.PlayerXWin : enGameStatus.PlayerOWin;
                return true;
            }

            else if (CheckVertical())
            {
                gameStatus = (currentPlayer == enPlayers.PlayerX) ? enGameStatus.PlayerXWin : enGameStatus.PlayerOWin;
                return true;
            }

            else if (CheckDiagonal())
            {
                gameStatus = (currentPlayer == enPlayers.PlayerX) ? enGameStatus.PlayerXWin : enGameStatus.PlayerOWin;
                return true;
            }

            return false;
        }

        private void GameMainFrame_Load(object sender, EventArgs e)
        {
            currentPlayer = enPlayers.PlayerX;
            UpdateTurnLabel();
            UpdateGameStatus();
        }

        private void BtnRestartGame_MouseLeave(object sender, EventArgs e)
        {
            BtnRestartGame.BackColor = Color.Black;
        }

        private void BtnRestartGame_MouseHover(object sender, EventArgs e)
        {
            BtnRestartGame.BackColor = Color.White;
        }

        private void PictureBox_MouseEnter(object sender, EventArgs e)
        {
            PictureBox pb = sender as PictureBox;
            if (pb != null)
                pb.BackColor = Color.LightGray; // Or your highlight color
        }

        private void PictureBox_MouseLeave(object sender, EventArgs e)
        {
            PictureBox pb = sender as PictureBox;
            if (pb != null)
                pb.BackColor = Color.Transparent;
        }

        private void PictureBox_Click(object sender, EventArgs e)
        {
            PictureBox pb = sender as PictureBox;
            if (pb != null)
            {
                string playerLetter = (currentPlayer == enPlayers.PlayerX) ? "X" : "O";
                pb.Tag = playerLetter;
                pb.Image = (playerLetter == "X") ? Properties.Resources.X : Properties.Resources.O;

                pb.Enabled = false; // disable the button to prevent user from clicking it again
                occupiedPositions++;
                
                if (!IsGameFinished())
                    SwitchTurn();
                else
                    DisableBoard();

                UpdateGameStatus();
            }
        }

        private void BtnRestartGame_Click(object sender, EventArgs e)
        {
            ResetBoard();
            occupiedPositions = 0;
            currentPlayer = enPlayers.PlayerX;
            gameStatus = enGameStatus.InProgress;
            UpdateGameStatus();
        }

        private void ResetBoard()
        {
            foreach (Control ctrl in this.Controls)
            {
                if (ctrl is PictureBox pb)
                {
                    if (pb.Tag != null && pb.Tag.ToString() == "MainPic")
                        continue;

                    pb.Tag = null;
                    pb.Enabled = true;
                    pb.Image = Properties.Resources.QuestionMark;
                }
            }
        }

        private void DisableBoard()
        {
            foreach (Control ctrl in this.Controls)
            {
                if (ctrl is PictureBox)
                    ctrl.Enabled = false;
            }
        }
    }
}
