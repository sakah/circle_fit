#include "TStyle.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
class Run
{
   public:
      Run(int irun, char* setup)
      {
         read_setup(irun, setup);

         char* data = Form("../output/run%d/output.txt", irun);
         read(data);
      };

      TTree *t;
      double max_chi2;
      char title[32];
      char turn_type[32];
      char noise_occupancy[32];
      double diff_threshold;

   private:
      void read(char* txt)
      {
         t = new TTree("t","t");
         t->SetMarkerStyle(20);
         t->ReadFile(txt,"iev/I:sig1:sig1in:sig1out:in1:in1sig:in1noise:sig2:sig2in:sig2out:in2:in2sig:in2noise:num:dr/D:deg:zhit:zfit:pthit:ptfit:pzhit:pzfit:chi2");
      };

      void read_setup(int irun, char* txt)
      {
         FILE* fp = fopen(txt,"r");
         if (fp==NULL) {
            fprintf(stderr,"ERROR: faield to open setup file %s\n", txt);
            return;
         }
         char line[128];
         int run_num;
         char type[32];
         char noise[32];
         double threshold;
         double maxchi2;

         while(fgets(line,sizeof(line),fp)) {
            sscanf(line, "%d %s %s %lf %lf",&run_num,type,noise,&threshold,&maxchi2);
            if (irun==run_num) {
               strcpy(turn_type,type);
               strcpy(noise_occupancy,noise);
               diff_threshold = threshold;
               max_chi2 = maxchi2;

               sprintf(title, "Run%d/%s/%s/%5.4f", run_num,type,noise,threshold);
            }
         }
         fclose(fp);
      };
};
struct Plot
{
   public:
      void plot(int plot_id, Run& run1, Run& run2, Run& run3, Run& run4)
      {
         gStyle->SetOptStat(111111);
         gStyle->SetOptFit();

         TH1F* h11 = get_chi2(run1.t, "t1", run1.title, run1.max_chi2);
         TH1F* h21 = get_chi2(run2.t, "t2", run2.title, run2.max_chi2);
         TH1F* h31 = get_chi2(run3.t, "t3", run3.title, run3.max_chi2);
         TH1F* h41 = get_chi2(run4.t, "t4", run4.title, run4.max_chi2);

         TH1F* h12 = get_ptres(run1.t, "t1", run1.title);
         TH1F* h22 = get_ptres(run2.t, "t2", run2.title);
         TH1F* h32 = get_ptres(run3.t, "t3", run3.title);
         TH1F* h42 = get_ptres(run4.t, "t4", run4.title);

         TH1F* h13 = get_pzres(run1.t, "t1", run1.title);
         TH1F* h23 = get_pzres(run2.t, "t2", run2.title);
         TH1F* h33 = get_pzres(run3.t, "t3", run3.title);
         TH1F* h43 = get_pzres(run4.t, "t4", run4.title);

         TH1F* h14 = get_z(run1.t, "t1", run1.title);
         TH1F* h24 = get_z(run2.t, "t2", run2.title);
         TH1F* h34 = get_z(run3.t, "t3", run3.title);
         TH1F* h44 = get_z(run4.t, "t4", run4.title);

         TCanvas* c1 = new TCanvas("c1", "chi2");
         c1->Divide(2,2);
         c1->cd(1); c1->cd(1)->SetGrid(); h11->Draw();
         c1->cd(2); c1->cd(2)->SetGrid(); h21->Draw();
         c1->cd(3); c1->cd(3)->SetGrid(); h31->Draw();
         c1->cd(4); c1->cd(4)->SetGrid(); h41->Draw();

         TCanvas* c2 = new TCanvas("c2", "ptres");
         c2->Divide(2,2);
         c2->cd(1); c2->cd(1)->SetGrid(); h12->Draw();
         c2->cd(2); c2->cd(2)->SetGrid(); h22->Draw();
         c2->cd(3); c2->cd(3)->SetGrid(); h32->Draw();
         c2->cd(4); c2->cd(4)->SetGrid(); h42->Draw();

         TCanvas* c3 = new TCanvas("c3", "pzres");
         c3->Divide(2,2);
         c3->cd(1); c3->cd(1)->SetGrid(); h13->Draw();
         c3->cd(2); c3->cd(2)->SetGrid(); h23->Draw();
         c3->cd(3); c3->cd(3)->SetGrid(); h33->Draw();
         c3->cd(4); c3->cd(4)->SetGrid(); h43->Draw();

         TCanvas* c4 = new TCanvas("c4", "zpos");
         c4->Divide(2,2);
         c4->cd(1); c4->cd(1)->SetGrid(); h14->Draw();
         c4->cd(2); c4->cd(2)->SetGrid(); h24->Draw();
         c4->cd(3); c4->cd(3)->SetGrid(); h34->Draw();
         c4->cd(4); c4->cd(4)->SetGrid(); h44->Draw();

         c1->Print(Form("pdf/chi2/c%d.pdf",  plot_id));
         c2->Print(Form("pdf/ptres/c%d.pdf", plot_id));
         c3->Print(Form("pdf/pzres/c%d.pdf", plot_id));
         c4->Print(Form("pdf/zpos/c%d.pdf",  plot_id));
      };

   private:
      TH1F* get_chi2(TTree* t, char* hname, char* htitle, double max_chi2)
      {
         char* hname1 = Form("h1-%s", hname);
         TH1F* h1 = new TH1F(hname1,Form("%s (chi2);reduced_chisquare",htitle),100,0,max_chi2);
         //t->Draw(Form("chi2/(num-5)>>%s", hname1),"chi2/(num-5)<5 && chi2/(num-5)>0");
         t->Draw(Form("chi2/(num-5)>>%s", hname1));
         return h1;
      };
      TH1F* get_ptres(TTree* t, char* hname, char* htitle)
      {
         char* hname1 = Form("h2-%s", hname);
         TH1F* h1 = new TH1F(hname1,Form("%s (ptres);(ptfit-pthit)/pthit",htitle),100,-1,1);
         t->Draw(Form("(ptfit-pthit)/pthit>>%s", hname1));
         h1->Fit("gaus","","",-0.1,0.1);
         return h1;
      };
      TH1F* get_pzres(TTree* t, char* hname, char* htitle)
      {
         char* hname1 = Form("h3-%s", hname);
         TH1F* h1 = new TH1F(hname1,Form("%s (pzres);(pzfit-pzhit)/pzhit",htitle),100,-2,2);
         t->Draw(Form("(pzfit-pzhit)/pzhit>>%s", hname1));
         h1->Fit("gaus","","",-0.5,0.5);
         return h1;
      };
      TH1F* get_z(TTree* t, char* hname, char* htitle)
      {
         char* hname1 = Form("h4-%s", hname);
         TH1F* h1 = new TH1F(hname1,Form("%s (zpos);zfit-zhit (cm)", htitle),100,-100,100);
         t->Draw(Form("zfit-zhit>>%s", hname1));
         h1->Fit("gaus","","",-20.,20.);
         return h1;
      };
};

void thre1()
{
   Run run1(1, "setup.txt");
   Run run2(2, "setup.txt");
   Run run3(3, "setup.txt");
   Run run4(4, "setup.txt");
   Plot plot; plot.plot(1,run1,run2,run3,run4);
}
void thre2()
{
   Run run1(5, "setup.txt");
   Run run2(6, "setup.txt");
   Run run3(7, "setup.txt");
   Run run4(8, "setup.txt");
   Plot plot; plot.plot(2,run1,run2,run3,run4);
}
void thre3()
{
   Run run1(9,  "setup.txt");
   Run run2(10, "setup.txt");
   Run run3(11, "setup.txt");
   Run run4(12, "setup.txt");
   Plot plot; plot.plot(3,run1,run2,run3,run4);
}
void thre4()
{
   Run run1(13, "setup.txt");
   Run run2(14, "setup.txt");
   Run run3(15, "setup.txt");
   Run run4(16, "setup.txt");
   Plot plot; plot.plot(4,run1,run2,run3,run4);
}
void all()
{
   thre1();
   thre2();
   thre3();
   thre4();
}
