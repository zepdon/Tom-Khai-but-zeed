#include "dialogueMaker/dialogueMaker.h"

int main() {
  // Create scenes
  /*
  Game::addScene("", "");
  */
  Game::addScene("Prologue", "ยินดีต้นรับเข้าสู่เกมไข่ต้ม คุณจะเล่นเป็นตัวละครนักผจญภัยนามว่าไข่ต้ม ผู้ซึ่งต้องการจะออกเดินทางทำตามสิ่งที่เขาได้รับมอบหมายมา การเลือกตัวเลือกของคุณจะทำให้โชคชะตาของไข่ต้มเปลี่ยนไปอย่างสิ้นเชิง คุณพร้อมหรือยังที่จะผจญภัยในโลกอันแสนกว้างใหญ่นี้?");
  Game::addScene("begin", "คุณตื่นขึ้นมาในโบราณสถานแห่งหนึ่ง มันเต็มไปด้วยซากปรักหักพังแต่ยังคงเค้าโครงความงามของสถานที่ไว้ได้ คุณกำลังเพลิดเพลินไปกับความงามราวกับฝัน แต่คุณรู้สึกเจ็บแปลบที่แขนขึ้นมาเล็กน้อยราวกับว่านี่มันใช่ฝัน ‘เอ๊ะ นี่ไม่ใช่ฝันอย่างนั้นนะเหรอ!’ คุณมีความรู้สึกว่าที่นี่ไม่ใช่ที่ที่คุณคุ้นเคย แต่คุณจำอะไรเกี่ยวกับตัวเองไม่ได้เลย นอกจากชื่อของคุณ “ไข่ต้ม”");
  Game::addScene("1-1", "ด้วยความที่คุณไม่รู้จักสถานที่แห่งนี้ คุณจึงลุกขึ้นมาแล้วเดินสำรวจไปรอบๆ สถานที่แห่งนี้สร้างด้วยหิน เรียงสลับทับซ้อนกันอย่างสวยงาม คุณเดินไปสักพักก็ได้สังเกตเห็นหินที่ผิดแปลกออกไปจากหินก้อนอื่น คุณจึงแตะมือลงไปอย่างสงสัย แต่แล้วมันก็ทำให้เส้นทางใหม่ในโบราณสถานแห่งนี้เปิดขึ้น มันเป็นเส้นทางที่เป็นบันไดทอดยาวลงไป คุณจึงเดินตามทางลงมาจนสุด แล้วได้พบกับโบราณวัตถุชิ้นนึง คุณตัดสินใจที่จะ");
  Game::addScene("2-1", "คุณตัดสินใจแตะมันลงไป แต่แล้วคุณก็สัมผัสได้ถึงบางอย่างที่แปลกไป สิ่งที่เหมือนกับพลังงานโบราณบางอย่างต้องการที่จะสื่อสารกับคุณ คุณสังเกตเห็นว่ามีอักษรโบราณปรากฏขึ้นบนวัตถุชิ้นนี้ ‘เพื่อให้โลกนี้สงบสุข เจ้าจะต้องช่วยชาวบ้านทั้งหลายเอาไว้ให้จงได้’ ตัวอักษรได้เปลี่ยนไปอีกครั้ง แล้วจึงปรากฏว่า ‘เจ้าต้องการยอมรับคำทำนายไหม’");
  Game::addScene("2-1{2}", "จู่ๆ เจ้าหินยักษ์นั่นก็พูดโพล่งขึ้นมาว่า ‘เพื่อให้โลกนี้สงบสุข เจ้าจะต้องช่วยชาวบ้านทั้งหลายเอาไว้ให้จงได้’ แล้วพูดว่า ‘เจ้าต้องการทำสิ่งนี้หรือไม่’");
  Game::addScene("2-2", "คุณพิจารณามันอยู่สักพัก ก็มีความรู้ที่สึกว่ามีอะไรบางอย่างกำลังคลืบคลานเข้ามา คุณตัดสินใจที่จะวิ่งไปข้างหน้าโดยไม่หันกลับไปมองด้านหลัง วิ่งไปเรื่อยๆก็เหมือนกับว่าทางที่คุณวิ่งมามีสภาพแวดล้อมคล้ายๆถ้ำ ‘นี่คือถ้ำที่อยู่ใต้ดินอย่างงั้นนะเหรอ’ คุณคิด ด้วยความกลัวคุณจึงวิ่งไปอย่างไม่รู้จุดหมาย รู้ตัวอีกทีก็หยุดอยู่ที่ข้างหน้าประตูยักษ์บานหนึ่ง มองไปรอบๆก็ไม่เห็นทางอื่นที่คุณสามารถไปได้แล้ว คุณจึงตัดสินใจผลักประตูเข้าไป คุณพบกับเจ้าก้อนหินขนาดใหญ่มหึมารูปร่างคล้ายมนุษย์ มันจะไม่เป็นอะไรเลยถ้ามันขยับไม่ได้ แต่นี่มันกำลังเดินมาทางนี้! คุณไม่มีเวลามาคิดอะไรแล้วพยายามที่จะวิ่งหนีออกไป แต่เจ้าก้อนหินยักษ์นั่นดันมาขวางคุณไว้");
  Game::addScene("3-1", "คุณสัมผัสได้ถึงสิ่งที่เหมือนกับพลังงานโบราณบางอย่างกำลังหมุนเวียนอยู่ในตัวคุณ บางสิ่งบางอย่างแปลกไป คุณรู้สึกได้ไม่นานก็มีแสงบางอย่างวิ่งเข้ามาหาตัวคุณอย่างจัง แสงนั่นมันทำให้คุณถูกวาร์ปไปยังสถานที่แห่งหนึ่ง ที่ที่เต็มไปด้วยดอกไม้นานาพันธุ์ ต้นไม้เขียวขจี และมีทะเลสาบขนาดใหญ่อยู่ที่แห่งนี้ด้วย คุณตกตะลึงไปกับภาพที่เห็น มันสวยงามมาก คุณตัดสินใจเดินเข้าไปใกล้ทะเลสาบ");
  Game::addScene("3-2", "คุณปฏิเสธคำทำนาย บางสิ่งบางอย่างแปลกไป คุณรู้สึกได้ไม่นานก็มีแสงบางอย่างวิ่งเข้ามาหาตัวคุณอย่างจัง แสงนั่นมันทำให้คุณถูกวาร์ปไปยังสถานที่แห่งหนึ่ง ที่ที่เต็มไปด้วยต้นไม้ที่มีเถาวัลย์พันเกี้ยวไปมาอย่างยุ่งเหยิง ได้ยินเสียงสัตว์ดุร้ายออกมาเป็นระยะๆ ");
  Game::addScene("3-2(2)", "คุณต่อรองไม่สำเร็จ บางสิ่งบางอย่างแปลกไป คุณรู้สึกได้ไม่นานก็มีแสงบางอย่างวิ่งเข้ามาหาตัวคุณอย่างจัง แสงนั่นมันทำให้คุณถูกวาร์ปไปยังสถานที่แห่งหนึ่ง ที่ที่เต็มไปด้วยต้นไม้ที่มีเถาวัลย์พันเกี้ยวไปมาอย่างยุ่งเหยิง ได้ยินเสียงสัตว์ดุร้ายออกมาเป็นระยะๆ ");

  Game::addScene("bad_ending", "You died.", true);
  Game::addScene("nice_ending", "You survived.", true);

  // Add options to scenes
  /*
  Game::addOption("", {
    {"", ""},
    {"", ""}
  });
  */

 //combine Prologue and begin ???
  Game::addOption("Prologue", {{"พิมพ์เลข 1 เพื่อเริ่มเกม","begin"}});

  Game::addOption("begin", {{"พิมพ์เลข 1 เพื่อเริ่มเกม","1-1"}});

  Game::addOption("1-1", {
    {"แตะที่โบราณวัตถุ", "2-1"},
    {"สังเกตอย่างละเอียดอย่างเดียว", "2-2"}
  });

  Game::addOption("2-1", {
    {"ยอมรับคำทำนาย", "3-1"},
    {"ปฏิเสธคำทำนาย", "3-2"}
  });

  Game::addOption("2-2", {
    {"เผชิญหน้ากับ Guardian", "2-1(2)"},
    {"ต่อรองกับ Guardian", "3-2(2)"}
  });

  Game::addOption("2-1(2)", {
    {"ยอมรับคำทำนาย", "3-1"},
    {"ปฏิเสธคำทำนาย", "3-2"}
  });

/*  Game::addOption("3-1", {
    {"ดื่มน้ำจากทะเลสาบ", ""},
    {"เดินสำรวจรอบบริเวณทะเลสาบ", ""}
  });
  
    Game::addOption("3-2", {
    {"เดินสำรวจลึกเข้าไปในป่า", ""},
    {"ถอยและทบทวนว่าจะเอาอย่างไรต่อ", ""}
  });

  Game::addOption("3-2(2)", {
    {"เดินสำรวจลึกเข้าไปในป่า", ""},
    {"ถอยและทบทวนว่าจะเอาอย่างไรต่อ", ""}
  });*/

  
  // Game loop
  Game::runGame("begin");
}
