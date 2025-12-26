# 2026-AtCoder-Study

- **스터디 방식**

1. 이 저장소(repository)를 fork 하여 자신의 원격 저장소로 복사해 갑니다.
2. 생성된 원격 저장소에 대회 이름에 맞는 폴더에 github_ID로 폴더를 만들고 그 안에 소스코드를 올립니다.
3. 소스코드 이름은 각 문제에 맞는 영어를 적으면 됩니다. ex) A.cpp B.py ...
4. commit 할 경우는 아래 commit 규칙을 지킵니다.
5. 대회가 끝나면 모든 문제를 commit 후 PR(pull request)합니다.
6. 대회가 끝나고 24시간 이내에 다른 사람들의 PR을 보고 코드 리뷰를 코멘트로 답니다.

[주의] 기존 폴더를 지우지 않게 조심하시고, 개인 폴더 내부만 수정해주세요.

- **commit 규칙**

  채점 결과 : `AC(accepted)` `TLE(Time Limit Exceeded)` `MLE(Memory Limit Exceeded)` `WA(Wrong Answer)`

  commit 메세지: 문제: [채첨결과]
  ex) A: AC

- **PR 규칙**

  PR 제목: 대회 이름 / GithubId  
  ex) ABC### / cnvxlns
  comment는 각 문제마다 풀이 방법과 어려웠던 내용을 설명합니다.

- **코드리뷰**

  PR에서 리뷰를 합니다. 코드의 각 줄에 리뷰를 해도 좋고, 전체 코드에 대한 느낀점이나 배운점을 작성해도 좋습니다.

  또한 상대방의 코드를 보고 개선점이나 의문점을 마음껏 적어도 좋습니다.

## Git 명령어

### fork 후 원격 저장소에서 로컬 저장소로 파일 받기

```bash
git clone https://github.com/[본인 Github 아이디]/2026-AtCoder-Study
```

### 로컬에서 파일 저장 후 원격 저장소로 올리기

```bash
git add A.cpp

git commit -m "A: AC"

git push origin main
```

### PR

Pull Request는 웹 github에서 진행하면 됩니다.
