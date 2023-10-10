#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

extern "C"
{
	#include <libavcodec/avcodec.h>
	#include <libavformat/avformat.h>
	#include <libavutil/dict.h>
}

int main(int argc, char** argv)
{
    std::cout << "Hello world!\n";
    AVFormatContext* fmt_ctx = nullptr;
    AVDictionaryEntry* tag = nullptr;
    int ret;
    const char* filenameIn = "D:\\LuxcodeVideo\\vied.mp4";
    std::string filenameOut = "D:\\LuxcodeVideo\\vied.txt";


    if ((ret = avformat_open_input(&fmt_ctx, filenameIn, 0, 0)))
        return ret;

    std::ofstream out;
    std::stringstream s;

    out.open(filenameOut);
    if (out.is_open()) {
        while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX)))
        {
            s << tag->key << "\t" << tag->value << '\n';
            out << s.str();
        }
    }
    out.close();
    avformat_close_input(&fmt_ctx);
    return 0;
}