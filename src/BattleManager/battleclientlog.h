#ifndef BATTLECLIENTLOG_H
#define BATTLECLIENTLOG_H

#include "battlecommandmanager.h"

class BattleData;
class BattleDynamicInfo;
class BattleDefaultTheme;

class BattleClientLog : public QObject, public BattleCommandManager<BattleClientLog>
{
    Q_OBJECT
public:
    BattleClientLog(BattleData *data, BattleDefaultTheme *theme);

    void onKo(int spot);
    void onSendOut(int spot, int player, std::shared_ptr<ShallowBattlePoke> pokemon, bool silent);
    void onSendBack(int spot);
    void onUseAttack(int spot, int attack);
    void onBeginTurn(int turn);
    void onHpChange(int spot, int newHp);
    void onHitCount(int spot, int count);
    void onEffectiveness(int spot, int effectiveness);
    void onCriticalHit(int spot);
    void onMiss(int spot);
    void onAvoid(int spot);
    void onStatBoost(int spot, int stat, int boost, bool silent);
    void onMajorStatusChange(int spot, int status, bool multipleTurns);
    void onPokeballStatusChanged(int player, int poke, int status);
    void onStatusAlreadyThere(int spot, int status);
    void onStatusNotification(int spot, int status);
    void onStatusDamage(int spot, int status);
    void onStatusOver(int spot, int status);
    void onAttackFailing(int spot);
    void onPlayerMessage(int spot, QString message);
    void onSpectatorJoin(int id, QString name);
    void onSpectatorLeave(int id);
    void onSpectatorChat(int id, QString message);
    void onMoveMessage(int spot, int move, int part, int type, int foe, int other, QString data);
    void onNoTarget(int spot);
    void onItemMessage(int spot, int item, int part, int foe, int berry, int other);
    void onFlinch(int spot);
    void onRecoil(int spot);
    void onDrained(int spot);
    void onStartWeather(int spot, int weather, bool ability);
    void onContinueWeather(int weather);
    void onEndWeather(int weather);
    void onHurtWeather(int spot, int weather);
    void onDamageDone(int spot, int damage);
    void onAbilityMessage(int spot, int ab, int part, int type, int foe, int other);
    void onSubstituteStatus(int spot, bool substitute);
    void onBlankMessage();
    void onClauseActivated(int clause);
    void onRatedNotification(bool rated);
    void onTierNotification(QString tier);
//    void onDynamicInfo(int spot, BattleDynamicInfo info);
//    void onPokemonVanish(int spot);
//    void onPokemonReappear(int spot);
//    void onSpriteChange(int spot, int newSprite);
//    void onDefiniteFormeChange(int spot, int poke, int newPoke);
//    void onCosmeticFormeChange(int spot, int subforme);
//    void onClockStart(int player, int time);
//    void onClockStop(int player, int time);
    void onShiftSpots(int player, int spot1, int spot2, bool silent);
    void onBattleEnd(int res, int winner);

    QString nick(int spot);
    QString rnick(int spot);

    void setTheme(BattleDefaultTheme *);

    /* Logs, but doesnt request a print */
    void pushHtml(const QString&);
    /* Requests a print, unless silent, in which case it calls pushHtml and add comments */
    void printHtml(const QString&, bool silent = false);
    void printLine(const QString&, bool silent = false);
signals:
    void lineToBePrinted(const QString &);
protected:
    BattleData *mData;
    BattleData *data();
    BattleDefaultTheme *mTheme;
    BattleDefaultTheme *theme();

    QList<QString> log;
    QHash<int, QString> spectators;
    bool blankMessage;
};

#endif // BATTLECLIENTLOG_H
