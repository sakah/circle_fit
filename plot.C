{
   TTree t;
   t.SetMarkerStyle(20);
   t.ReadFile("debug.txt","iev/I:sig1:sig1in:sig1out:sig2:sig2in:sig2out:num:dr/D:deg:zhit:zfit:pthit:ptfit:pzhit:pzfit:chi2");
}
