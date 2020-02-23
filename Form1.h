#pragma once
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#define MaxStack 1000

	int **maze, **mazeX;
	struct offset
	{    
		int x, y;
	};

	enum direction {E,S,W,N}; // 考慮4個方向

	struct position//決定位置
	{    
		int x, y;
		direction dir;
	};

	position stack [MaxStack];//堆疊
	int top;

namespace My0413418_HW3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->splitContainer1->Panel1->Controls->Add(this->checkBox2);
			this->splitContainer1->Panel1->Controls->Add(this->button4);
			this->splitContainer1->Panel1->Controls->Add(this->groupBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label4);
			this->splitContainer1->Panel1->Controls->Add(this->checkBox1);
			this->splitContainer1->Panel1->Controls->Add(this->button3);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Size = System::Drawing::Size(683, 372);
			this->splitContainer1->SplitterDistance = 249;
			this->splitContainer1->TabIndex = 0;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(158, 287);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(60, 16);
			this->checkBox2->TabIndex = 18;
			this->checkBox2->Text = L"random";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(151, 309);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 36);
			this->button4->TabIndex = 17;
			this->button4->Text = L"清除";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(214, 126);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(32, 25);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(117, 22);
			this->textBox2->TabIndex = 17;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox2_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(7, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 12);
			this->label2->TabIndex = 16;
			this->label2->Text = L"p=";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(161, 28);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 36);
			this->label5->TabIndex = 15;
			this->label5->Text = L"請輸入\r\n奇數\r\n且p>m";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(32, 55);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 22);
			this->textBox1->TabIndex = 13;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(6, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 12);
			this->label1->TabIndex = 7;
			this->label1->Text = L"m=";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(32, 83);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(146, 42);
			this->button2->TabIndex = 4;
			this->button2->Text = L"generate maze";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(26, 273);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 72);
			this->label4->TabIndex = 12;
			this->label4->Text = L"顏色說明:\r\n外牆為藍色\r\n障礙物為橘色\r\n可走路徑為粉色\r\n走過路徑為黃色\r\n最短路徑為淺藍";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(158, 265);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(56, 16);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"refresh";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button3->Font = (gcnew System::Drawing::Font(L"標楷體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(44, 212);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(146, 42);
			this->button3->TabIndex = 2;
			this->button3->Text = L"走迷宮";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(44, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 42);
			this->button1->TabIndex = 0;
			this->button1->Text = L"load maze";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(430, 372);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->richTextBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 23);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(422, 345);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"迷宮形式1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(416, 339);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 23);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(422, 345);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"迷宮形式2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(416, 339);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->listBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 23);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(422, 345);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"最佳路徑";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(3, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(416, 339);
			this->listBox1->TabIndex = 0;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(683, 372);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"Form1";
			this->Text = L"mouse in maze  by Jack 2016/11/11 ver1.0";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion

		int ** generatemaze(int ** maze, int x, int y)
		{  
			int direction;
			 maze[x][y] =0;  // 標示此格已設定
			while (maze[x][y+2]==1 || maze[x+2][y]==1 || maze[x][y-2]==1 || maze[x-2][y]==1) // 如果不是外牆
			{  
				direction = rand()%4+1;  // 決定下一個位置
				if (direction==1 && maze[x][y+2]==1) // 向右走
				{    
					maze[x][y+1] =0; // 拆掉右牆
					maze = generatemaze(maze, x,y+2);
				}
				else if (direction==2 && maze[x-2][y]==1) // 向上走
				{  
					maze[x-1][y] =0; // 拆掉上牆
					maze = generatemaze(maze, x-2,y);
				}
                else if (direction==3 && maze[x][y-2]==1) // 向左走
				{ 
					maze[x][y-1] =0; // 拆掉右牆
					maze = generatemaze(maze, x,y-2);
				}
				else if (direction==4 && maze[x+2][y]==1) // 向下走
				{  
					maze[x+1][y] =0; // 拆掉上牆
					maze = generatemaze(maze, x+2,y);
				}
			}
			return maze;
		}


		int m,p;
			void push(position step)
				{
					if (top == Height*Width) richTextBox1->AppendText("Stack is full");//堆疊已滿
					else stack[++top] = step;
				}

				position pop()
				{
					if (top == -1) listBox1->Items->Add("Stack is empty");//堆疊空
					else return stack[top--];
				}

			void MouseInMaze(int **maze, int Height, int Width)
				{  
					int i, j, u, v , g_Height , g_Width ;
					g_Height = m ;
					g_Width = p ;
					bool found = false;
					offset move[4];//準備4個方向
					move[E].x = 0; move[E].y = 1;
					move[S].x = 1; move[S].y = 0;
					move[W].x = 0; move[W].y = -1;
					move[N].x = -1; move[N].y = 0;
					position step;
					maze[1][0] = 3;//開始行走
					step.x = 1; step.y = 1; step.dir = E;//定義第一步
					maze[1][1] = 3;//入口
					dataGridView1->Rows[1]->Cells[0]->Style->BackColor = Color::SkyBlue;//改顏色
					if (checkBox1->Checked == true) dataGridView1->Refresh();
					dataGridView1->Rows[1]->Cells[1]->Style->BackColor = Color::SkyBlue;//改顏色
					if (checkBox1->Checked == true) dataGridView1->Refresh();
					push(step);
					while (top != -1 && !found) // 持續移動直到堆疊空
					{   
						step = pop();
						i = step.x;
						j = step.y; 
						step.dir = step.dir;
						while (step.dir <= N && !found)
						{
							u = i + move[step.dir].x;//移動i
							v = j + move[step.dir].y;//移動j
							if (u == g_Height-2 && v == g_Width-1)// 找到出口
							{
								int remember[100][3];
								found = true;
								step.x = i; 
								step.y = j;
								int count=top;
								maze[u][v] = 3;
								push(step);
								dataGridView1->Rows[u]->Cells[v]->Style->BackColor = Color::SkyBlue;//改顏色
								if (checkBox1->Checked == true) dataGridView1->Refresh();
								while (top != -1)// 從入口到出口的所有堆疊
								{
									position s = pop();
									int dd = s.dir;
									remember[top+1][0]=s.x  ;
									remember[top+1][1]=s.y  ;
									remember[top+1][2]=dd;
								}

								remember[0][0] = 1;//設定初始
								remember[0][1] = 0;//設定初始
								for(i=0;i<=count;i++)
								{
									int plus = i+1 ;
									if(remember[i][2]==0){listBox1->Items->Add("Step:(" +remember[i][0] + "," + remember[i][1] + ")"+ "向上");}
									else if(remember[i][2]==1){listBox1->Items->Add("Step:(" +remember[i][0] + "," + remember[i][1] + ")"+ "向右");}
									else if(remember[i][2]==2){listBox1->Items->Add("Step:(" + remember[i][0] + "," + remember[i][1] + ")"+ "向下");}
									else {listBox1->Items->Add("Step:(" + remember[i][0] + "," + remember[i][1] + ")"+ "向左");}
									listBox1->Items->Add("    ↓");	
								}
								
								int x1 = m-1 ;
								int y2 = p-2 ;
								listBox1->Items->Add("走到("+x1+","+y2+")"+"結束");//顯示出口
								listBox1->Items->Add("-------------------------------------------------------------------");	
							}
					

							if (maze[u][v] == 0)//可以走的路
							{
								maze[u][v] = 3; //標示走過的路
								dataGridView1->Rows[u]->Cells[v]->Style->BackColor = Color::SkyBlue; //改顏色
								if (checkBox1->Checked == true) dataGridView1->Refresh();
								step.x = i; step.y = j; step.dir = direction(step.dir + 1);
								push(step);//放入堆疊
								i = u; 
								j = v; 
								step.dir = E;//移動到可行步伐
							}
							else
								step.dir = direction(step.dir + 1);
						}
						if(!found)dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Yellow;//走回頭為黃色
						if (checkBox1->Checked == true) dataGridView1->Refresh();
					}
				}
						

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 String ^ S;
				 int pos, i, j;
				

				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
				{ // 順利開啟檔案才繼續往下做
					richTextBox1->LoadFile(openFileDialog1->FileName, RichTextBoxStreamType::PlainText);
					S= richTextBox1 ->Lines[0] ;//屬性
					richTextBox1 ->AppendText("\n"+S);//加字串
					pos= S-> IndexOf(" ");
					richTextBox1 ->AppendText("\npos = "+pos);//加字串
					m = int::Parse(S->Substring( 0, pos));
					p = int::Parse(S->Substring( pos+1 , S->Length-pos-1 ));
					richTextBox1 ->AppendText(" m = "+m+" p = "+p);//加字串
					maze = new int * [m] ;
				
					for(i=0 ; i < m ; i++)
					{
						maze[i] = new int [p];
					}

					for(i=1 ; i <= m ; i++)
					{
						S= richTextBox1 ->Lines[i] ;//填入迷宮
						for(j=0 ; j<p ; j++)
						{
							maze[i-1][j] =int::Parse( S->Substring(2*j,1));
						}
					}

					dataGridView1->RowCount = m+1;
					dataGridView1->ColumnCount = p+1;
					for(i=0 ; i< m ; i++)
					{
						for(j=0 ; j< p ; j++)
							{
							//dataGridView1->Rows[i]->Cells[j]->Value = maze[i][j];
							if(maze[i][j] == 1)
								dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Orange;//障礙物橘色
							else if(maze[i][j] == 2) 
								dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Blue;//外牆藍色
							else
								dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Pink;//可走路線粉紅
							}
					}
				}
			}

		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
				 {
					int i, j, m, p;
					if (maze) //刪除迷宮
					{
						for (int i = 0; i < m ; i++) 
						delete[]maze[i];
						delete[]maze;
					}

					m = int::Parse(textBox1->Text);
					p = int::Parse(textBox2->Text);
					int Start_i = 1, Start_j = 1, End_i =m-1, End_j= p-1;
					
					mazeX = new int * [m+2]; //產生迷宮用 (m+2)*(p+2);外層多一層
					for (int i = 0; i <= m+1 ; i++)
					{
						mazeX[i] = new int [p+2];
					}
					for (int i = 0; i <= m+1 ; i++)
					{
						for (int j = 0; j <= p+1 ; j++)
						{
							if((i==0) || (j==0) || (i==m+1) || (j==p+1))
								mazeX[i][j]=4 ; //最外層
							else
								mazeX[i][j]=1; //初始迷宮內部
						}
					}
					mazeX = generatemaze(mazeX, End_i, End_j); // 產生迷宮
					for (i=1; i <= m; i++)
					{
						for (j=1; j <= p; j++)
						{
							if((i==1) || (j==1) || (i==m) || (j==p))
								mazeX[i][j]= 2;//之前保留的外牆拆除
						}
					}
					mazeX[Start_i+1][Start_j] =0; // 拆掉入口左牆
					mazeX[End_i][End_j+1] =0; // 拆掉出口右牆
					maze = new int * [m];
					for(i=0 ; i< m ; i++)
						maze[i]= new int [p];
					for(i=0 ; i< m ; i++)
						for(j=0 ; j< p ; j++)
							maze[i][j]=mazeX[i+1][j+1];//調整出入口

					dataGridView1->RowCount = m ;
					dataGridView1->ColumnCount = p ;
					char buffer[200];
					for (i=0; i<m; i++)
					{   
						for (j=0; j<p; j++)
						{
							itoa(maze[i][j], buffer, 10);//轉換成字串
							richTextBox1->AppendText(maze[i][j]+" ");
						}
						richTextBox1->AppendText("\n");
					}
					richTextBox1->AppendText("------------------------------------------------------------");

					for(i=0 ; i< m ; i++)
					{
						dataGridView1->Columns[i] ->Width=36 ;
						for(j=0 ; j<p ; j++)
						{
							if(maze[i][j]==2) 
								dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Blue;//障礙物橘色
							else if (maze[i][j]==1) 
								dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Orange;//外牆藍色
							else
								dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Pink;//可走路線粉紅
						}
					}
				}

			private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
					 {
						 if  ( textBox1->Text == "" && textBox2->Text == "" ) //如果m,p已知(讀檔情況下)
						{
							MouseInMaze(maze,m,p);
						}
						else//如果m,p是使用者自訂
						{
							m = int::Parse(textBox1->Text);
							p = int::Parse(textBox2->Text);
							MouseInMaze(maze,m,p);
						}
					 }
			private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
						{//防呆
							if (isdigit(e->KeyChar) || iscntrl(e->KeyChar))
							{
								e->Handled = false;
							}
							else
							{
								e->Handled = true;
							}
						}

				private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
						 {//防呆
							if (isdigit(e->KeyChar) || iscntrl(e->KeyChar))
							{
								e->Handled = false;
							}
							else
							{
								e->Handled = true;
							}
						 }

				private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
							 for(int i=0;i<m;i++)
							 {
								for(int j=0;j<p;j++)
								{
									dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::PowderBlue;
									if (checkBox1->Checked == true) {dataGridView1->Refresh();}
								}
							}
			 
							if (checkBox2->Checked == true)
							{
								for(int r=0;r<500;r++)
								{
									int qx=rand()%m;
									int qy=rand()%p;
				 					dataGridView1->Rows[qx]->Cells[qy]->Style->BackColor = Color::PowderBlue;
									dataGridView1->Refresh();
								}
							}
						 }
};
			}