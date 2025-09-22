#pragma once

static int iStatic = 0;
extern int iExtern; // 외부변수. 이런 변수가 있다는 것만 알려주는 거임. 어떤 파일이건 상관 없지만 나중에 초기화 시켜서 정의 해둬야함. ex) func.cpp