#define COUNT 3
void (*anim[COUNT])();

void PLAY_ANIMATION(int index){

}

void DEFINE_ANIMATIONS(){
  anim[0] = face;
  anim[1] = cara;
  anim[2] = spiral;
}

void face(){
  for (int i = 0; i<3; i++)
  {
    sprite(face1, ORCHID, 500);
    sprite(face2, ORCHID, 500);
    sprite(face3, ORCHID, 500);
    sprite(face4, ORCHID, 500);
    sprite(face5, ORCHID, 500);

  }
}
void cara()
{
  for (int i = 0; i<3; i++)
  {
    sprite(cara2, DEEPSKYBLUE, 700);
    sprite(cara3, BLUE, 700);
  }
}
void spiral()
{
  for (int i = 0; i<3; i++)
  {
    sprite(rot1, RED, wait);
    sprite(rot2, PINK, wait);
    sprite(rot3, BLUE, wait);
    sprite(rot4, MAGENTA, wait);
  }
}
void heart()
{
  for (int i = 0; i<3; i++)
  {
    sprite(cuore1, RED, wait);
    sprite(cuore1, PINK, wait);
    sprite(cuore1, BLUE, wait);
    sprite(cuore1, MAGENTA, wait);
  }
}
void dance()
{
  for (int i = 0; i<10; i++)
  {
    sprite(dance1, PINK, 300);
    sprite(dance2, PINK, 300);
    sprite(dance3, PINK, 300);
    sprite(dance4, PINK, 300);
    sprite(dance5, PINK, 300);
  }

}

void space()
{
  unsigned long COLOR = RED;
  for (int i = 0; i<2; i++)
  {
    sprite(alienoa1, BLUE, wait);
    sprite(alienoa2, BLUE, wait);
    sprite(alienoa1, BLUE, wait);
    sprite(alienoa2, BLUE, wait);
  }
  for (int i = 0; i<2; i++)
  {
    sprite(alienob1, COLOR, wait);
    sprite(alienob2, COLOR, wait);
    sprite(alienob1, COLOR, wait);
    sprite(alienob2, COLOR, wait);
  }
  for (int i = 0; i<2; i++)
  {
    sprite(alienoc1, VIOLET, wait);
    sprite(alienoc2, VIOLET, wait);
    sprite(alienoc1, VIOLET, wait);
    sprite(alienoc2, VIOLET, wait);
  }
  for (int i = 0; i<2; i++)
  {
    sprite(navicella1, COLOR, wait);
    sprite(navicella2, COLOR, wait);
    sprite(navicella3, COLOR, wait);
    sprite(navicella4, COLOR, wait);
  }
}
void pacman()
{
  sprite(pacman1, YELLOW, wait);
  sprite(pacman2, YELLOW, wait);
  sprite(pacman1, YELLOW, wait);
  sprite(pacman2, YELLOW, wait);
  sprite(pacman3, YELLOW, wait);
  sprite(pacman4, YELLOW, wait);
  sprite(pacman5, YELLOW, wait);
  sprite(pacman1, YELLOW, wait);
  sprite(pacman2, YELLOW, wait);
  sprite(pacman1, YELLOW, wait);
  sprite(pacman3, YELLOW, wait);
  sprite(gost4, RED, wait);
  sprite(gost5, RED, wait);
  sprite(gost1, RED, wait);
  sprite(gost2, RED, wait);
  sprite(gost3, RED, wait);
  sprite(gost4, HOTPINK, wait);
  sprite(gost5, HOTPINK, wait);
  sprite(gost1, HOTPINK, wait);
  sprite(gost2, HOTPINK, wait);
  sprite(gost3, HOTPINK, wait);
  sprite(gost4, ORANGE, wait);
  sprite(gost5, ORANGE, wait);
  sprite(gost1, ORANGE, wait);
  sprite(gost2, ORANGE, wait);
  sprite(gost3, ORANGE, wait);
  sprite(gost4, AQUA, wait);
  sprite(gost5, AQUA, wait);
  sprite(gost1, AQUA, wait);
  sprite(gost2, AQUA, wait);
  sprite(gost3, AQUA, wait);
  sprite(pacman1, YELLOW, wait);
  sprite(pacman2, YELLOW, wait);
  sprite(pacman1, YELLOW, wait);
  sprite(pacman2, YELLOW, wait);
  sprite(pacman3, YELLOW, wait);
  sprite(pacman4, YELLOW, wait);
  sprite(pacman5, YELLOW, wait);
  sprite(pacman1, YELLOW, wait);
  sprite(pacman2, YELLOW, wait);
  sprite(pacman1, YELLOW, wait);
  sprite(pacman3, YELLOW, wait);
}

void dog()
{
  for (int i = 0; i<3; i++)
  {
    sprite(dog1, SADDLEBROWN, 1000);
    sprite(dog2, SADDLEBROWN, 1000);
    sprite(dog3, SADDLEBROWN, 1000);
  }
}
void battito()
{
  for (int i = 0; i<3; i++)
  {
    sprite(cuore1, RED, 400);
    sprite(cuore2, RED, 200);
    sprite(cuore3, RED, 100);
    sprite(cuore2, RED, 200);
    sprite(cuore1, RED, 400);
    sprite(cuore2, RED, 200);
    sprite(cuore3, RED, 100);
    sprite(cuore2, RED, 200);
  }
}
