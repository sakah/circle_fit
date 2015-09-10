{
   TTree t;
   t.SetMarkerStyle(20);
   t.ReadFile("debug.txt","iev/I:sig1:sig1in:sig1out:in1:in1sig:in1noise:sig2:sig2in:sig2out:in2:in2sig:in2noise:num:dr/D:deg:zhit:zfit:pthit:ptfit:pzhit:pzfit:chi2");
}
