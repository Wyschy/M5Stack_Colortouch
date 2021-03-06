
    class Colortouch  {
      private:
      int framecolor;
      int buttoncolor;
      int buttoncolorpressed;
      int buttonx;
      int buttony;
      int buttonw;
      int buttonh;
      bool buttonstate;
      char buttontext;

      public:
      void setup(int x, int y, int w, int h, int frame, int area, int pressed, char text) {
        buttonx = x;
        buttony = y;
        buttonw = w;
        buttonh = h;
        framecolor = frame;
        buttoncolor = area;
        buttoncolorpressed = pressed;
        buttontext = text;
       
        
        M5.Lcd.drawRoundRect(buttonx,buttony,buttonw,buttonh,10,framecolor);
        M5.Lcd.fillRoundRect(buttonx+1,buttony+1,buttonw-2,buttonh-2,10,buttoncolor);
        M5.Lcd.setCursor(buttonx+10,buttony+10);
        M5.Lcd.print(buttontext);
        
      }
      bool bpress()  {
        //M5.update();

        Event& e = M5.Buttons.event;
        if (e & (E_MOVE | E_RELEASE)) {
          M5.Lcd.fillRoundRect(buttonx+1,buttony+1,buttonw-2,buttonh-2,10,buttoncolor);
          M5.Lcd.setCursor(buttonx+10,buttony+10);
          M5.Lcd.print(buttontext);
          buttonstate = false;
        }
        
        if (e & (E_TOUCH | E_MOVE)) {
          Point p = e & E_MOVE ? e.from : e.to;
          if (p.x > buttonx && p.x < buttonx+buttonw && p.y > buttony && p.y < buttony+buttonh) {
            M5.Lcd.fillRoundRect(buttonx+1,buttony+1,buttonw-2,buttonh-2,10,buttoncolorpressed);
            M5.Lcd.setCursor(buttonx+10,buttony+10);
            M5.Lcd.print(buttontext);
            buttonstate = true;
          }
        }
      
      return (buttonstate);
      }
        
    };

class Frametouch  {
      private:
      int framecolor;
      int buttonx;
      int buttony;
      int buttonw;
      int buttonh;
      bool buttonstate;
      char buttontext;

      public:
      void setup(int x, int y, int w, int h, int frame, char text) {
        buttonx = x;
        buttony = y;
        buttonw = w;
        buttonh = h;
        framecolor = frame;
        buttontext = text;       
        
        M5.Lcd.drawRoundRect(buttonx,buttony,buttonw,buttonh,10,framecolor);
        M5.Lcd.setCursor(buttonx+10,buttony+10);
        M5.Lcd.print(buttontext);
        
      }
      bool bpress()  {
        //M5.update();

        Event& e = M5.Buttons.event;
        if (e & (E_MOVE | E_RELEASE)) {
          M5.Lcd.drawRoundRect(buttonx,buttony,buttonw,buttonh,10,framecolor);
          M5.Lcd.setCursor(buttonx+10,buttony+10);
          M5.Lcd.print(buttontext);
          buttonstate = false;
        }
        
        if (e & (E_TOUCH | E_MOVE)) {
          Point p = e & E_MOVE ? e.from : e.to;
          if (p.x > buttonx && p.x < buttonx+buttonw && p.y > buttony && p.y < buttony+buttonh) {
            M5.Lcd.drawRoundRect(buttonx,buttony,buttonw,buttonh,10,BLACK);
            M5.Lcd.setCursor(buttonx+10,buttony+10);
            M5.Lcd.print(buttontext);
            buttonstate = true;
          }
        }
      
      return (buttonstate);
      }
        
    };


