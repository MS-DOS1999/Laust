var HexaBank2=[0x01,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
  0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x05,
  0x03,0x49,0x6C,0x00,0x70,0x72,0x65,0x6E,0x64,0x00,
  0x6C,0x61,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
  0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
  0x03,0x70,0x6F,0x75,0x73,0x73,0x69,0x65,0x72,0x65,
  0x2E,0x00,0x00,0x00,0x00,0x00,0x00,0x16,0x00,0x08,
  0x02,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
  0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x06];

for(i=0; i<HexaBank2.length; i++){
		HexaBank2[i] += 0x80;
    HexaBank2[i] = "0x" + HexaBank2[i].toString(16).toUpperCase();
} 

for(i=0; i<160; i++){
	HexaBank2.push("NULL");
}

document.getElementById("lel").innerHTML = HexaBank2;