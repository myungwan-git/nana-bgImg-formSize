
#include <nana/gui.hpp>
// For nana::picture
#include <nana/gui/widgets/picture.hpp>
// For nana::screen
#include <nana/gui/screen.hpp>

#include <iostream>

int main() {
	nana::form frm;

	auto s = nana::screen();
	auto pa = s.get_primary().workarea();
	
	std::cout << "pa.width = " << pa.width << std::endl;
	std::cout << "pa.height = " << pa.height << std::endl;
	std::cout << "pa.x = " << pa.x << std::endl;
	std::cout << "pa.y = " << pa.y << std::endl;

	frm.move(pa.x + pa.width / 4, pa.y + pa.height/4);
	frm.outline_size({ 500, 500 });



	nana::picture pic(frm);
	nana::place plc(frm);
	
	pic.load(nana::paint::image("../exambmp.bmp"));
	plc["pic"] << pic;
	plc.collocate();
	frm.show();
	nana::exec();

	return 0;
}


/*
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/place.hpp>
#include <iostream>

int main() {
	using namespace nana;
	form fm;
	button btn(fm, "Normal Button");
	btn.events().click([]() {std::cout << "Normal Button clicked.\n"; });
	button btn0(fm, "Basic Mode");

	//It is basic mode when the third parameter of effects_bground() is specified by zero.
	API::effects_bground(btn0, effects::bground_transparent(0), 0);
	button btn1(fm, "Blend Mode: Transparent");
	API::effects_bground(btn1, effects::bground_transparent(0), 0.5);
	button btn2(fm, "Blend Mode: Blur");
	API::effects_bground(btn2, effects::bground_blur(2), 0.5);
	label lb0(fm, ("Normal Label"));

	//lb0.fgcolor(color_rgb(0xFFFFFF));
	lb0.events().click([]() {std::cout << "Label clicked too.\n"; });
	label lb1(fm, ("Basic Mode: Transparent"));
	lb1.fgcolor(color_rgb(0xFFFFFF));

	//Equal to lb1.transparent(true);
	API::effects_bground(lb1, effects::bground_transparent(0), 0);
	label lb2(fm, ("Basic Mode: Transparent and blend with its background color"));
	lb2.fgcolor(color_rgb(0xFFFFFF));
	lb2.bgcolor(color_rgb(0xFF0000));
	API::effects_bground(lb2, effects::bground_transparent(10), 0);
	label lb3(fm, "Basic Mode: Blur");
	lb3.fgcolor(color_rgb(0xFFFFFF));
	API::effects_bground(lb3, effects::bground_blur(2), 0);
	place pl(fm);
	pl.div("<><weight=80% abc vertical gap=5><>");
	pl["abc"] << btn << btn0 << btn1 << btn2 << lb0 << lb1 << lb2 << lb3;
	pl.collocate();
	fm.show();
	nana::paint::image img("../exambmp.bmp");
	drawing dw(fm);
	dw.draw([&img](nana::paint::graphics & graph) {
		if (img.empty()) return;
		img.paste(graph, nana::point{});
	});
	dw.update();
	exec(
#ifdef NANA_AUTOMATIC_GUI_TESTING
		1, 1, [&btn, &lb0]() {
		click(btn);
		click(lb0);
	}
#endif

	);
}
*/



/*
#include <nana/gui.hpp>
#include <nana/gui/widgets/picture.hpp>
#include <nana/gui/place.hpp>
#include <iostream>

#define NANA_ENABLE_JPEG

int main() {
	using namespace nana;
	form fm;
	picture picPNG{ fm },
		picJPEG{ fm },
		picBMP{ fm };
	place p{ fm };
	p.div("pic");
#ifdef  NANA_ENABLE_PNG
	std::cout << "PNG execute!\n";
	picPNG.load(paint::image("../Examples/png.png"));
	p["pic"] << picPNG;
#endif
#ifdef  NANA_ENABLE_JPEG
	std::cout << "JPEG execute!\n";
	picJPEG.load(paint::image("../exambmp.bmp"));
	p["pic"] << picJPEG;
#endif
	picBMP.load(paint::image("../exambmp2.bmp"));
	p["pic"] << picBMP;
	p.collocate();
	fm.show();
	exec();
}
*/


/*
#include <nana/gui/screen.hpp>
#include <nana/gui.hpp>
int main() {
	using namespace nana;
	auto s = screen();
	auto pa = s.get_primary().workarea();
	form fm0, fm1, fm2, fm3;
	fm0.move(pa.x, pa.y);
	fm0.outline_size({ pa.width / 2, pa.height / 2 });
	fm0.caption("screen 0");
	fm1.move(pa.x + pa.width / 2, pa.y);
	fm1.outline_size({ pa.width / 2, pa.height / 2 });
	fm1.caption("screen 1");
	fm2.move(pa.x, pa.y + pa.height / 2);
	fm2.outline_size({ pa.width / 2, pa.height / 2 });
	fm2.caption("screen 2");
	fm3.move(pa.x + pa.width / 2, pa.y + pa.height / 2);
	fm3.outline_size({ pa.width / 2, pa.height / 2 });
	fm3.caption("screen 3");
	fm0.show();
	fm1.show();
	fm2.show();
	fm3.show();
	exec();
}
*/