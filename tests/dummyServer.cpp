#include <mc_rtc/GUIState.h>
#include <mc_control/ControllerServer.h>

struct DummyProvider
{
  double value = 42.0;
  Eigen::Vector3d point = Eigen::Vector3d(0., 1., 2.);
};

struct TestServer
{
  TestServer();

  void publish();

  mc_control::ControllerServer server {1.0, 1.0, {"ipc:///tmp/mc_rtc_pub.ipc"}, {"ipc:///tmp/mc_rtc_rep.ipc"}};
  DummyProvider provider;
  mc_rtc::gui::StateBuilder builder;
  bool check_ = true;
  std::string string_ = "default";
  int int_ = 0;
  double d_ = 0.;
  Eigen::VectorXd v_ {Eigen::VectorXd::Ones(6)};
  Eigen::Vector3d v3_ {1., 2., 3.};
  std::string combo_ = "b";
  std::string data_combo_;
};

TestServer::TestServer()
{
  auto data = builder.data();
  data.add("DataComboInput", std::vector<std::string>{"Choice A", "Choice B", "Choice C", "Obiwan Kenobi"});
  builder.addElement({"dummy", "provider"}, mc_rtc::gui::Label("value",
                                                               [this](){ return provider.value; }));
  builder.addElement({"dummy", "provider"}, mc_rtc::gui::ArrayLabel("point",
                                                                    [this](){ return provider.point; }));
  builder.addElement({"dummy", "provider"}, mc_rtc::gui::ArrayLabel("point with labels", {"x", "y", "z"},
                                                                    [this](){ return provider.point; }));
  builder.addElement({"Button example"}, mc_rtc::gui::Button("Push me",
                                                             [](){ LOG_INFO("Button pushed") }));
  builder.addElement({"Checkbox example"}, mc_rtc::gui::Checkbox("Checkbox",
                                                             [this](){ return check_;},
                                                             [this](){ check_ = !check_; }));
  builder.addElement({"StringInput example"}, mc_rtc::gui::StringInput("StringInput",
                                                             [this](){ return string_;},
                                                             [this](const std::string & data){ string_ = data; std::cout << "string_ changed to " << string_ << std::endl; }));
  builder.addElement({"IntegerInput example"}, mc_rtc::gui::IntegerInput("IntegerInput",
                                                             [this](){ return int_;},
                                                             [this](int data){ int_ = data; std::cout << "int_ changed to " << int_ << std::endl; }));
  builder.addElement({"NumberInput example"}, mc_rtc::gui::NumberInput("NumberInput",
                                                             [this](){ return d_;},
                                                             [this](double data){ d_ = data; std::cout << "d_ changed to " << d_ << std::endl; }));
  builder.addElement({"ArrayInput example"}, mc_rtc::gui::ArrayInput("ArrayInput",
                                                             [this](){ return v_;},
                                                             [this](const Eigen::VectorXd & data){ v_ = data; std::cout << "v_ changed to " << v_.transpose() << std::endl; }));
  builder.addElement({"ArrayInput with labels example"}, mc_rtc::gui::ArrayInput("ArrayInput with labels", {"x", "y", "z"},
                                                             [this](){ return v3_;},
                                                             [this](const Eigen::Vector3d & data){ v3_ = data; std::cout << "v3_ changed to " << v3_.transpose() << std::endl; }));
  builder.addElement({"ComboInput"}, mc_rtc::gui::ComboInput("ComboInput", {"a", "b", "c", "d"},
                                                             [this](){ return combo_;},
                                                             [this](const std::string & s){ combo_ = s; std::cout << "combo_ changed to " << combo_ << std::endl; }));
  builder.addElement({"DataComboInput"}, mc_rtc::gui::DataComboInput("DataComboInput", {"DataComboInput"},
                                                             [this](){ return data_combo_;},
                                                             [this](const std::string & s){ data_combo_ = s; std::cout << "data_combo_ changed to " << data_combo_ << std::endl; }));
}

void TestServer::publish()
{
  server.handle_requests(builder);
  server.publish(builder);
}

int main()
{
  TestServer server;
  while(1)
  {
    server.publish();
    usleep(50000);
  }
  return 0;
}
